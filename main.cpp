#include<iostream>
#include<boost/beast/core.hpp>
#include<boost/beast/http.hpp>
#include<boost/asio.hpp>



namespace beast = boost::beast;
namespace http = beast::http;             
namespace net = boost::asio;              
using tcp = boost::asio::ip::tcp;       




int main() {
try {
    net::io_context ioc;

    //bind listener
    tcp::acceptor acceptor(ioc, {tcp::v4(),8080});


    while(true) {
        
        //create a new socket
        tcp::socket socket(ioc);

        //wait to accept the connection
        acceptor.accept(socket);;
        //read the http request
        beast::flat_buffer buffer;
        http::request<http::string_body> req;
        http::read(socket,buffer,req);

        //prepare the http response
    

        http::response<http::string_bosy res{http::status::ok,req.version()};
        res.set(http::field::server,"this is boost beast http server");
        res.set(http::field::content_type,"text/plain");
        rees.keep_alive(req.keep_alive());
        res.body() = "Hello sanjeev!!\n";
        res.prepare_payload();


        //send the http response

        http::write(socket,res);

    }

} catch (const std::exception& e) {
    std::cerr << "Error" << e.what() <<std::endl;
    return 1;
}
    return 0;
}














}