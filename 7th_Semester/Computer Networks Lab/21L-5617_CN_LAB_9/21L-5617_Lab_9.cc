#include "ns3/core-module.h"
#include "ns3/network-module.h"
#include "ns3/internet-module.h"
#include "ns3/point-to-point-module.h"
#include "ns3/applications-module.h"
#include "ns3/traffic-control-module.h"

using namespace ns3;

int main(int argc, char *argv[])
{
    LogComponentEnable("UdpClient", LOG_LEVEL_INFO);
    LogComponentEnable("UdpServer", LOG_LEVEL_INFO);
    LogComponentEnable("OnOffApplication", LOG_LEVEL_INFO);

    NodeContainer num_nodes;
    num_nodes.Create(4);

    PointToPointHelper n0n2, n1n2, n2n3;
    n0n2.SetDeviceAttribute("DataRate", StringValue("2Mbps"));
    n0n2.SetChannelAttribute("Delay", StringValue("10ms"));

    n1n2.SetDeviceAttribute("DataRate", StringValue("2Mbps"));
    n1n2.SetChannelAttribute("Delay", StringValue("10ms"));

    n2n3.SetDeviceAttribute("DataRate", StringValue("1.7Mbps"));
    n2n3.SetChannelAttribute("Delay", StringValue("20ms"));

    NetDeviceContainer dev0to2 = p2p1.Install(nodes.Get(0), nodes.Get(2));
    NetDeviceContainer dev1to2 = p2p2.Install(nodes.Get(1), nodes.Get(2));
    NetDeviceContainer dev2to3 = p2p3.Install(nodes.Get(2), nodes.Get(3));

    InternetStackHelper stack;
    stack.Install(nodes);

    Ipv4AddressHelper address;
    address.SetBase("10.1.1.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces0to2 = address.Assign(dev0to2);

    address.SetBase("10.1.2.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces1to2 = address.Assign(dev1to2);

    address.SetBase("10.1.3.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces2to3 = address.Assign(dev2to3);

    uint16_t udpPort = 4000;
    UdpServerHelper udpServer(udpPort);
    ApplicationContainer serverApp = udpServer.Install(nodes.Get(3));
    serverApp.Start(Seconds(0.0));
    serverApp.Stop(Seconds(5.0));

    UdpClientHelper udpClient(interfaces2to3.GetAddress(1), udpPort);
    udpClient.SetAttribute("MaxPackets", UintegerValue(1000));
    udpClient.SetAttribute("Interval", TimeValue(MilliSeconds(10))); 
    udpClient.SetAttribute("PacketSize", UintegerValue(1024));       

    ApplicationContainer clientApp = udpClient.Install(nodes.Get(0));
    clientApp.Start(Seconds(0.1));
    clientApp.Stop(Seconds(4.5));

    uint16_t tcpPort = 5000;
    Address sinkAddress(InetSocketAddress(interfaces2to3.GetAddress(1), tcpPort));
    PacketSinkHelper tcpSink("ns3::TcpSocketFactory", sinkAddress);
    ApplicationContainer sinkApp = tcpSink.Install(nodes.Get(3));
    sinkApp.Start(Seconds(0.0));
    sinkApp.Stop(Seconds(5.0));

    OnOffHelper tcpSource("ns3::TcpSocketFactory", sinkAddress);
    tcpSource.SetAttribute("OnTime", StringValue("ns3::ConstantRandomVariable[Constant=1]"));
    tcpSource.SetAttribute("OffTime", StringValue("ns3::ConstantRandomVariable[Constant=0]"));
    tcpSource.SetAttribute("DataRate", DataRateValue(DataRate("1Mbps")));
    tcpSource.SetAttribute("PacketSize", UintegerValue(1024)); 

    ApplicationContainer sourceApp = tcpSource.Install(nodes.Get(1));
    sourceApp.Start(Seconds(0.5));
    sourceApp.Stop(Seconds(4.0));

    n0n2.EnablePcapAll("udp-cbr");
    n1n2.EnablePcapAll("tcp-ftp");

    Simulator::Stop(Seconds(5.0));
    Simulator::Run();
    Simulator::Destroy();

    return 0;
}
