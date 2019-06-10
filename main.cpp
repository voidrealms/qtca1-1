#include <QCoreApplication>
#include <QDebug>
#include <QThread>
#include <QDateTime>

//exploring the main thread - threads control the execution, think of a thread as "time on the CPU"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qInfo() << "App Thread: " << a.thread();
    qInfo() << "Current Thread: " << QThread::currentThread();

    Q_ASSERT(a.thread() == QThread::currentThread());


    qInfo() << "Running: " << QThread::currentThread()->isRunning();
    qInfo() << "LoopLevel: " << QThread::currentThread()->loopLevel();
    qInfo() << "StackSize: " << QThread::currentThread()->stackSize();
    qInfo() << "Finished: " << QThread::currentThread()->isFinished();
    qInfo() << "Before: " << QDateTime::currentDateTime().toString();
    QThread::sleep(5);
    qInfo() << "After: " << QDateTime::currentDateTime().toString();

    return a.exec();
}
