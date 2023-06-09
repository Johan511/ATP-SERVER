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



std::shared_ptr<tcp::socket> socket = std::make_shared<tcp::socket>(acceptor_.get_executor());

acceptor_.async_accept(*socket, [socket](const boost::system::error_code& ec){

if(!ec){

 socket->async_read_some(boost::asio::buffer(data_, max_length),
                [socket](const boost::system::error_code& ec, std::size_t length) {
                    if (!ec) {

                        std::cout<<MESSAGE<<std::endl;
                        std::cout << std::string(data_, length) << std::endl;
                    }
                });
}

});





}

int main() {

    boost::asio::io_context io;
    tcp::acceptor acceptor_(tcp::acceptor(io, tcp::endpoint(tcp::v4(), 8000)));

    start_accept(acceptor_);

    io.run();
}
