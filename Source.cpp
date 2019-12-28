#include <iostream>
#include "Subscriber.h"

#include "figure.h"
#include "rhombus.h"
#include "trapezoid.h"
#include "rectangle.h"


struct ThreadFunc {
public:
    ThreadFunc(const Executor& executor) : executor(executor) {};

    void addTask(std::unique_ptr<Task> task) {

        std::lock_guard<std::mutex> lock(queueMutex);
        tasks.push(std::move(task));

    }

    void startWorking() {
        working = true;
    }

    void stopWorking() {
        working = false;
    }

    bool isWorking() {
        return working;
    }

    std::condition_variable& getCondition1() {
        return condition1;
    }
    
    std::condition_variable& getCondition2() {
        return condition2;
    }

    std::mutex& getReadMutex() {
        return readMutex;
    }

    void operator()() {
        while(true) {
            std::unique_lock<std::mutex> mainLock(readMutex);
            while(!working) {
                condition2.wait(mainLock);
            }
            if(!tasks.empty()) {
                {
                    std::lock_guard<std::mutex> lock(queueMutex);
                    std::shared_ptr<Task> currentTask = std::move(tasks.front());
                    tasks.pop();
                    if(currentTask->isExit()) {
                        break;
                    } else {
                         executor.notify(std::move(currentTask));
                    }
                    this->stopWorking();
                    condition1.notify_one();
                }
            }

        }
    }
private:
    Executor executor;
    std::mutex readMutex;
    std::condition_variable condition1;
    std::condition_variable condition2;
    std::mutex queueMutex;
    std::queue<std::shared_ptr<Task>> tasks;
    bool working = false;
};

void menu() {
    std::cout << "1 : add\n";
    std::cout << "0 : exit\n";
    std::cout << "> ";
}

int main(int argc, char** argv) {

    unsigned bufferSize;
    if(argc != 2) {
        std::cout << "No args!" << std::endl;
        return -1;
    }

    bufferSize = std::atoi(argv[1]);
    std::vector<std::shared_ptr<Figure>> figures;
    int command;
    int command2;

    std::shared_ptr<Subscriber> consolePrint(new ConsoleSubscriber());
    std::shared_ptr<Subscriber> filePrint(new FileSubscriber());
    
    Executor executor;
    executor.subscribe(consolePrint);
    executor.subscribe(filePrint);
    
    ThreadFunc func(executor);
    std::thread thread(std::ref(func));

    while(true) {
        menu();
        std::cin >> command;


        if(command == 0) {
            std::unique_ptr<Task>t(new Task(true, figures));

            func.addTask(std::move(t));
            func.startWorking();
            func.getCondition2().notify_one();
            break;
        } else if(command == 1) {
            std::shared_ptr<Figure> f;
            std::cout << "1 - Rhombus, 2 - Rectangle, 3 - Trapezoid" << std::endl;
            std::cin >> command2;
            try {
                if(command2 == 1) {
                    f = std::make_shared<Rhombus>();
                    f -> input(std::cin);
                } else if(command2 == 2) {
                    f = std::make_shared<Rectangle>();
                    f -> input(std::cin); 
                } else if(command2 == 3) {
                    f = std::make_shared<Trapezoid>();
                    f -> input(std::cin);
                } else {
                    std::cout << "Wrong input" << std::endl;
                }
                figures.push_back(f);
            } catch(std::exception& e) {
                std::cerr << e.what() << std::endl;
            }
            if(figures.size() == bufferSize) {
                std::unique_ptr<Task>t(new Task(false, figures));
                func.addTask(std::move(t));

                func.startWorking();
                func.getCondition2().notify_one();
                std::unique_lock<std::mutex> lock(func.getReadMutex());
                while(func.isWorking()) {
                    func.getCondition1().wait(lock);
                }
                figures.resize(0);
            }
        } else {
            std::cout << "Unknown command" << std::endl;
        }    
    }
    thread.join();
    return 0;
}