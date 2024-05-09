#ifndef SPACESHOOTAN_NETW_H
#define SPACESHOOTAN_NETW_H

#include <memory>
#include <optional>
#include <vector>

#include "SFML/Network/IpAddress.hpp"
#include "SFML/Network/Packet.hpp"
#include "SFML/Network/TcpListener.hpp"
#include "SFML/Network/TcpSocket.hpp"

namespace networking{

    class INetWorker{
    public:
        virtual sf::Socket::Status init() = 0;
        virtual void send(sf::Packet) = 0;
        virtual std::optional<sf::Packet> receive() = 0;
    };

    class NetServer: public INetWorker{
    private:
        int port;
        sf::IpAddress adr;
        sf::TcpListener listener;
        std::vector<sf::TcpSocket*> connections;
        sf::TcpSocket* last_connection;
    public:
        NetServer(int port, sf::IpAddress adr);
        sf::Socket::Status init() override;
        void send(sf::Packet) override;
        std::optional<sf::Packet> receive() override;

    };

    class NetClient: public INetWorker{
    private:
        int port;
        sf::IpAddress adr;
        sf::TcpSocket connection;
    public:
        NetClient(int port, sf::IpAddress adr);
        sf::Socket::Status init() override;
        void send(sf::Packet) override;
        std::optional<sf::Packet> receive() override;
    };

    static INetWorker* currentWorker = nullptr;

    template<typename T>
    typename std::enable_if<std::is_base_of<INetWorker, T>::value, sf::Socket::Status>::type
    createWorker(int port, sf::IpAddress adr){
        delete currentWorker;

        currentWorker = new T(port, adr);
        return currentWorker->init();
    }
}


#endif //SPACESHOOTAN_NETW_H
