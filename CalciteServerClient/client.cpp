//
// Created by he on 10/28/18.
//

#include "CalciteServer.h"
#include <config.h>
#include <transport/TSocket.h>
#include <transport/TBufferTransports.h>
#include <protocol/TBinaryProtocol.h>
#include <iostream>


using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;

using boost::shared_ptr;


int main(int argc, char **argv) {
    boost::shared_ptr<TSocket> socket(new TSocket("localhost", 8099));
    boost::shared_ptr<TTransport> transport(new TFramedTransport(socket));
    boost::shared_ptr<TProtocol> protocol(new TBinaryProtocol(transport));

    transport->open();

    TPlanResult t;

    CalciteServerClient calcite(protocol);

    calcite.sql2Plan(t,"1","2","default","select * from T1",true,false);

    std::cout<<"plan:"<<t.plan_result<<std::endl;

    transport->close();
    return 0;
}