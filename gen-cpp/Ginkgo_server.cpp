// This autogenerated skeleton file illustrates how to build a server.
// You should copy it to another filename to avoid overwriting it.

#include "Ginkgo.h"
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/server/TNonblockingServer.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/TBufferTransports.h>
#include <thrift/concurrency/ThreadManager.h>
#include <thrift/concurrency/PosixThreadFactory.h>
#include <thrift/server/TThreadPoolServer.h>
#include <thrift/server/TThreadedServer.h>


#include <vector>
#include <iostream>

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;
using namespace ::apache::thrift::concurrency;

using boost::shared_ptr;

class GinkgoHandler : virtual public GinkgoIf {
public:
    GinkgoHandler() {
        // Your initialization goes here
        TTableDescriptor t1;
        t1.tableName = "T1";
        Attribute a1;
        a1.attrName = "t1_id";
        a1.attrType = column_type::INT;
        t1.attributes.push_back(a1);
        Attribute a2;
        a2.attrName = "name";
        a2.attrType = column_type::STRING;
        t1.attributes.push_back(a2);

        TTableDescriptor t2;
        t2.tableName = "T3";
        Attribute a3;
        a3.attrName = "t2_id";
        a3.attrType = column_type::INT;
        t2.attributes.push_back(a3);
        Attribute a4;
        a4.attrName = "phone";
        a4.attrType = column_type::STRING;
        t2.attributes.push_back(a4);

        t_list_.push_back(t1);
        t_list_.push_back(t2);
    }

    void get_tables_meta(std::vector<TTableDescriptor> & _return) {
        // Your implementation goes here
        printf("get_tables_meta\n");
        std::cout << "tables_meta.size():" << t_list_.size() << std::endl;
        _return=t_list_;
    }


    void get_table_descriptor(TTableDescriptor &_return, const std::string &table_name) {
        // Your implementation goes here
        printf("get_table_descriptor\n");
        for (int i = 0; i < t_list_.size(); ++i) {
            if (t_list_[i].tableName == table_name) {
                _return = t_list_[i];
            }
        }
    }

private:
    std::vector<TTableDescriptor> t_list_;
};

int main(int argc, char **argv) {
    int port = 9090;
    shared_ptr<GinkgoHandler> handler(new GinkgoHandler());
    shared_ptr<TProcessor> processor(new GinkgoProcessor(handler));
    shared_ptr<TServerTransport> serverTransport(new TServerSocket(port));
    shared_ptr<TTransportFactory> transportFactory(new TBufferedTransportFactory());
    shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());
    shared_ptr<ThreadManager> threadManager = ThreadManager::newSimpleThreadManager(15);//指定10个线程数
    shared_ptr<PosixThreadFactory> threadFactory = shared_ptr<PosixThreadFactory>(new PosixThreadFactory());
    threadManager->threadFactory(threadFactory);
    threadManager->start();



    std::cout << "Ginkgo server start!" << std::endl;

//    TThreadPoolServer server(processor, serverTransport, transportFactory, protocolFactory,
//                             threadManager);//使用线程池

//    TSimpleServer server(processor, serverTransport, transportFactory, protocolFactory);

    //TNonblockingServer server(processor, protocolFactory, port);//不使用线程池

    TNonblockingServer server(processor, protocolFactory, port,
                              threadManager);//使用线程池
    server.serve();
    return 0;
}

