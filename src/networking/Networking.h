#ifndef SPACESHOOTAN_NETWORKING_H
#define SPACESHOOTAN_NETWORKING_H

#include <memory>
#include <optional>
#include <vector>

#include "SFML/Network/IpAddress.hpp"
#include "SFML/Network/Packet.hpp"
#include "SFML/Network/TcpListener.hpp"
#include "SFML/Network/TcpSocket.hpp"
#include "SFML/System/String.hpp"

namespace networking{

    class INetWorker{
    public:
        virtual sf::Socket::Status init() = 0;
        virtual void send(sf::Packet) = 0;
        virtual std::optional<sf::Packet> receive() = 0;
        virtual void setId(int) = 0;
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
        ~NetServer();
        sf::Socket::Status init() override;
        void send(sf::Packet) override;
        std::optional<sf::Packet> receive() override;
        void setId(int) override;
    };

    class NetClient: public INetWorker{
    private:
        int port;
        sf::IpAddress adr;
        sf::TcpSocket connection;
        int id;
    public:
        NetClient(int port, sf::IpAddress adr);
        sf::Socket::Status init() override;
        void send(sf::Packet) override;
        std::optional<sf::Packet> receive() override;
        void setId(int) override;
    };

    class Networking{
    public:
        INetWorker* worker = nullptr;

        template<typename T>
        typename std::enable_if<std::is_base_of<INetWorker, T>::value, sf::Socket::Status>::type
        createWorker(int port, sf::IpAddress adr){
            delete worker;

            worker = new T(port, adr);
            return worker->init();
        }
    };

}


#endif //SPACESHOOTAN_NETWORKING_H
