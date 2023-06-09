#include <boost/asio.hpp>
#include <cstdlib>
#include <iostream>
#include <memory>
#include <utility>

using boost::asio::ip::tcp;

using std::cin, std::cout, std::endl;
const int max_length = 100;
char data_[100] = {};

static const std::string MESSAGE("connection has been made");

void start_accept(tcp::acceptor &acceptor_) {

}

int main() {

    boost::asio::io_context io;
    tcp::acceptor acceptor_(tcp::acceptor(io, tcp::endpoint(tcp::v4(), 8000)));

    start_accept(acceptor_);

    io.run();
}