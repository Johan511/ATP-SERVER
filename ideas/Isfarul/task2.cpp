#include <boost/asio.hpp>
#include <cstdlib>
#include <iostream>
#include <memory>
#include <system_error>
#include <utility>

// compiles but doesnt work


using boost::asio::ip::tcp;

using std::cin, std::cout, std::endl;
const int max_length = 100;
char data_[100] = {};

static const std::string MESSAGE("connection has been made");

void start_accept(tcp::acceptor &acceptor_) {
    // something wrong here
    const tcp::socket &socket =
        static_cast<tcp::socket>(acceptor_.get_executor());
    acceptor_.async_accept([&](std::error_code error, tcp::socket socket) {
        if (!error) {
            cout << MESSAGE + '\n';
            socket.async_read_some(
                boost::asio::buffer(data_, max_length),
                [](std::error_code error, std::size_t length) {
                    if (!error)
                        cout<< std::string(data_, length);
                    else
                        std::cerr << "Error encountered\nError code: "
                                  << error.value() << '\n'
                                  << error.message() << '\n';
                });
        } else
            std::cerr << "Error encountered\nError code: " << error.value()
                      << '\n'
                      << error.message() << '\n';
        ;
    });
}

int main() {

    boost::asio::io_context io;
    tcp::acceptor acceptor_(tcp::acceptor(io, tcp::endpoint(tcp::v4(), 8000)));

    start_accept(acceptor_);

    io.run();
}
