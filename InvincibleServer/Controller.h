#ifndef INVINCIBLESERVER_CONTROLLER_H
#define INVINCIBLESERVER_CONTROLLER_H

#include <iostream>
#include <vector>
#include <fstream>
#include "DataStructures/LinkedList.h"
#include "Singleton.h"
#include "FaultTolerance.h"
#include "DataBase.h"
#include "VideoHandler.h"

class Controller {

private:
    int parityDisc = 0;

    int getParityDisk();

    std::string getPart(std::string name, int diskNum);

    void restoreDisk(int diskNum);

public:
    void sendParts(std::vector<byte> data, std::string filename);

    std::string getVideo(std::string name);

    void addDisk(sf::TcpSocket *socket);

};


#endif //INVINCIBLESERVER_CONTROLLER_H
