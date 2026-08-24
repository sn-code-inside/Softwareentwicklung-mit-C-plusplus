// P008KD_Coroutines.cpp
#include <Windows.h>
#include <iostream>
#include <coroutine>

void printConsole(LPCTSTR lpConsoleTitle)
{
    SetConsoleTitle(lpConsoleTitle);
}
// 1. Der Rückgabetyp der Coroutine
struct Generator                                                                            //1
{
    struct promise_type 
    {
        int current_value;
        // Erzeugt das Generator-Objekt beim Start der Coroutine
        Generator get_return_object() {                                                     //2
            return Generator { std::coroutine_handle<promise_type>::from_promise(*this) };
        }
        std::suspend_always initial_suspend() { 
            return {}; 
        }                                //3 
        std::suspend_always final_suspend() noexcept { 
            return {}; 
        }                         
        void unhandled_exception() { std::terminate(); }
        void return_void() {}                               
        std::suspend_always yield_value(int value)                                          //4
        {
            current_value = value;
            return {};                                                                      //5
        }
    };
    std::coroutine_handle<promise_type> handle;
    Generator(std::coroutine_handle<promise_type> h) {
        handle = h;                                                                         //6
    }
    ~Generator() 
    { 
        if (handle) 
            handle.destroy();                                                               //7
    }
    bool next()                                                                             //8
    {
        if (handle) 
        {
            handle.resume();
            return !handle.done();
        }
        return false;
    }
    int value() 
    { 
        return handle.promise().current_value;                                              //9
    }
};
// 2. Die eigentliche Coroutine
Generator count(int start, int end)                                                         //10
{
    for (int i = start; i <= end; ++i) 
    {
        co_yield i; // Pausiert und gibt 'i' zurück
    }
}
// 3. Verwendung
int main(void) 
{
    //=========================================
    LPCTSTR str = L"P008KD_Coroutines";
    printConsole(str);
    //=========================================
    auto gen = count(1, 5);
    while (gen.next()) 
    {
        std::cout << gen.value() << " "; // Ausgabe: 1 2 3 4 5
    }
    return 0;
}

/*
co_yield:       Dies ist der magische Moment. Die Coroutine speichert ihren lokalen 
                Zustand (den Wert von i und den Punkt in der Schleife), gibt den Wert an das promise-Objekt weiter und pausiert.
handle.resume():Der Aufrufer in main entscheidet aktiv, wann die Coroutine weiterarbeiten darf.
Stackless:      Beachte, dass die Variable i innerhalb von count über die Aufrufe von next() hinweg 
                erhalten bleibt, obwohl die Funktion zwischendurch technisch gesehen "verlassen" wurde.

#include <boost/asio.hpp>
#include <iostream>

using boost::asio::ip::tcp;
using boost::asio::awaitable;
using boost::asio::use_awaitable;

// Eine asynchrone Coroutine, die einen einzelnen Client bedient
awaitable<void> handle_client(tcp::socket socket) {
    try {
        char data[1024];
        for (;;) {
            // co_await pausiert die Coroutine, bis Daten gelesen wurden
            // Der Thread wird währenddessen NICHT blockiert.
            std::size_t n = co_await socket.async_read_some(boost::asio::buffer(data), use_awaitable);

            // Schreibt die Daten asynchron zurück
            co_await async_write(socket, boost::asio::buffer(data, n), use_awaitable);
        }
    } catch (std::exception& e) {
        std::cerr << "Client Error: " << e.what() << "\n";
    }
}

// Der Listener, der neue Verbindungen akzeptiert
awaitable<void> listener() {
    auto executor = co_await boost::asio::this_coro::executor;
    tcp::acceptor acceptor(executor, {tcp::v4(), 5555});

    for (;;) {
        // Wartet asynchron auf eine neue Verbindung
        tcp::socket socket = co_await acceptor.async_accept(use_awaitable);

        // Startet handle_client als neue, unabhängige Coroutine (Task)
        boost::asio::co_spawn(executor, handle_client(std::move(socket)), boost::asio::detached);
    }
}

int main() {
    boost::asio::io_context io_context;
    boost::asio::co_spawn(io_context, listener(), boost::asio::detached);
    io_context.run(); // Startet den Event-Loop
}


*/