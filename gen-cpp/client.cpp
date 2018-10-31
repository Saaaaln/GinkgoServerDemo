//
// Created by he on 10/28/18.
//

#include "Ginkgo.h"
#include <config.h>
#include <vector>
#include <transport/TSocket.h>
#include <transport/TBufferTransports.h>
#include <protocol/TBinaryProtocol.h>
#include <iostream>


using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;

using boost::shared_ptr;


int main(int argc, char **argv) {
    boost::shared_ptr<TSocket> socket(new TSocket("localhost", 9090));
    boost::shared_ptr<TTransport> transport(new TFramedTransport(socket));
    boost::shared_ptr<TProtocol> protocol(new TBinaryProtocol(transport));

    transport->open();

    TTableDescriptor t;

    std::vector<TTableDescriptor> t_list;

    GinkgoClient ginkgo(protocol);

    ginkgo.get_tables_meta(t_list);

    std::cout<<"t_list:"<<t_list.size()<<std::endl;

    ginkgo.get_table_descriptor(t,"T1");

    std::cout<<"t_name:"<<t.tableName<<std::endl;

    transport->close();
    return 0;
}