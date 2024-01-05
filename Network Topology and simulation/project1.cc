/*Network Toplogy*/

#include "ns3/core-module.h"
#include "ns3/network-module.h"
#include "ns3/internet-module.h"
#include "ns3/point-to-point-module.h"
#include "ns3/applications-module.h"
#include "ns3/netanim-module.h"
#include "ns3/mobility-module.h"
#include "ns3/flow-monitor-module.h"
using namespace ns3;

NS_LOG_COMPONENT_DEFINE ("FirstScriptExample");

Ptr<FlowMonitor> monitor;
FlowMonitorHelper flowmon;


void averageThroughput()
{

        Ptr<Ipv4FlowClassifier> classifier = DynamicCast<Ipv4FlowClassifier> (flowmon.GetClassifier ());
        std::map<FlowId, FlowMonitor::FlowStats> stats = monitor->GetFlowStats ();
        for (std::map<FlowId, FlowMonitor::FlowStats>::const_iterator i = stats.begin (); i != stats.end (); ++i)
        {
                Ipv4FlowClassifier::FiveTuple t = classifier->FindFlow (i->first);
                std::cout << "Flow " << i->first  << " (" << t.sourceAddress << " -> " << t.destinationAddress << ")\n";
                std::cout << "  Tx Packets: " << i->second.txPackets << "\n";
                std::cout << "  Tx Bytes:   " << i->second.txBytes << "\n";
                std::cout << "  Throughput:  " << i->second.txBytes * 8.0 / (i->second.timeLastRxPacket.GetSeconds() - i->second.timeFirstTxPacket.GetSeconds()) / 1024 / 1024  << " Mbps\n";
                std::cout << "  Rx Packets: " << i->second.rxPackets << "\n";
                std::cout << "  Rx Bytes:   " << i->second.rxBytes << "\n";
                std::cout << "  Goodput: " << i->second.rxBytes * 8.0 / (i->second.timeLastRxPacket.GetSeconds() - i->second.timeFirstTxPacket.GetSeconds()) / 1024 / 1024  << " Mbps\n";
        }

}

int
main (int argc, char *argv[])
{
        //generate nodes
        NodeContainer nodes;
        nodes.Create (30);

        //connect nodes

        //link1
        NodeContainer s1e2;
        s1e2.Add(nodes.Get(0));
        s1e2.Add(nodes.Get(17));

        //link2
        NodeContainer s2e2;
        s2e2.Add(nodes.Get(1));
        s2e2.Add(nodes.Get(17));

       //link3
        NodeContainer s3e1;
        s3e1.Add(nodes.Get(2));
        s3e1.Add(nodes.Get(16));

        //link4
        NodeContainer s4e1;
        s4e1.Add(nodes.Get(3));
        s4e1.Add(nodes.Get(16));


        //link5
        NodeContainer s5e3;
        s5e3.Add(nodes.Get(4));
        s5e3.Add(nodes.Get(18));


        //link6
        NodeContainer s6e2;
        s6e2.Add(nodes.Get(5));
        s6e2.Add(nodes.Get(17));


         //link7
        NodeContainer s7e1;
        s7e1.Add(nodes.Get(6));
        s7e1.Add(nodes.Get(16));

    
         //link8
        NodeContainer s8e3;
        s8e3.Add(nodes.Get(7));
        s8e3.Add(nodes.Get(18));

        //link9
        NodeContainer e4d1;
        e4d1.Add(nodes.Get(19));
        e4d1.Add(nodes.Get(8));

        //link10
        NodeContainer e5d2;
        e5d2.Add(nodes.Get(20));
        e5d2.Add(nodes.Get(9));

        //link11
        NodeContainer e4d3;
        e4d3.Add(nodes.Get(19));
        e4d3.Add(nodes.Get(10));

         //link12
        NodeContainer e5d4;
        e5d4.Add(nodes.Get(20));
        e5d4.Add(nodes.Get(11));

        //link13
        NodeContainer e6d5;
        e6d5.Add(nodes.Get(21));
        e6d5.Add(nodes.Get(12));

        //link14
        NodeContainer e6d6;
        e6d6.Add(nodes.Get(21));
        e6d6.Add(nodes.Get(13));


        //link15
        NodeContainer e2d7;
        e2d7.Add(nodes.Get(17));
        e2d7.Add(nodes.Get(14));


        //link16
        NodeContainer e4d8;
        e4d8.Add(nodes.Get(19));
        e4d8.Add(nodes.Get(15));


        //link17
        NodeContainer e1b1;
        e1b1.Add(nodes.Get(16));
        e1b1.Add(nodes.Get(22));


        //link18
        NodeContainer e2b2;
        e2b2.Add(nodes.Get(17));
        e2b2.Add(nodes.Get(23));


        //link19
        NodeContainer b1b2;
        b1b2.Add(nodes.Get(22));
        b1b2.Add(nodes.Get(23));


        //link20
        NodeContainer b1b7;
        b1b7.Add(nodes.Get(22));
        b1b7.Add(nodes.Get(28));


        //link21
        NodeContainer b2b7;
        b2b7.Add(nodes.Get(23));
        b2b7.Add(nodes.Get(28));

        //link22
        NodeContainer b2b8;
        b2b8.Add(nodes.Get(23));
        b2b8.Add(nodes.Get(29));

        //link23
        NodeContainer e3b3;
        e3b3.Add(nodes.Get(18));
        e3b3.Add(nodes.Get(24));

        //link24
        NodeContainer b3b8;
        b3b8.Add(nodes.Get(24));
        b3b8.Add(nodes.Get(29));

        //link25
        NodeContainer b8b7;
        b8b7.Add(nodes.Get(29));
        b8b7.Add(nodes.Get(28));

        //link26
        NodeContainer b7b6;
        b7b6.Add(nodes.Get(28));
        b7b6.Add(nodes.Get(27));

        //link27
        NodeContainer b6e6;
        b6e6.Add(nodes.Get(27));
        b6e6.Add(nodes.Get(21));


        //link28
        NodeContainer b7b5;
        b7b5.Add(nodes.Get(28));
        b7b5.Add(nodes.Get(26));


        //link29
        NodeContainer b8b5;
        b8b5.Add(nodes.Get(29));
        b8b5.Add(nodes.Get(26));

        //link30
        NodeContainer b8b4;
        b8b4.Add(nodes.Get(29));
        b8b4.Add(nodes.Get(25));

        //link31
        NodeContainer b3b4;
        b3b4.Add(nodes.Get(24));
        b3b4.Add(nodes.Get(25));


        //link32
        NodeContainer b5e5;
        b5e5.Add(nodes.Get(26));
        b5e5.Add(nodes.Get(20));


        //link33
        NodeContainer b4e4;
        b4e4.Add(nodes.Get(25));
        b4e4.Add(nodes.Get(19));
       

        //Link Capacity Setting


        PointToPointHelper pointToPoint;
        pointToPoint.SetDeviceAttribute ("DataRate", StringValue ("50Mbps"));
        pointToPoint.SetChannelAttribute ("Delay", StringValue (".5ms"));
        NetDeviceContainer c_s1e2 = pointToPoint.Install(s1e2);
        NetDeviceContainer c_s2e2 = pointToPoint.Install(s2e2);
        NetDeviceContainer c_s3e1 = pointToPoint.Install(s3e1);
        NetDeviceContainer c_s4e1 = pointToPoint.Install(s4e1);
        NetDeviceContainer c_s5e3 = pointToPoint.Install(s5e3);
        NetDeviceContainer c_s6e2 = pointToPoint.Install(s6e2);
        NetDeviceContainer c_s7e1 = pointToPoint.Install(s7e1);
        NetDeviceContainer c_s8e3 = pointToPoint.Install(s8e3);



        NetDeviceContainer c_e4d1 = pointToPoint.Install(e4d1);
        NetDeviceContainer c_e5d2 = pointToPoint.Install(e5d2);
        NetDeviceContainer c_e4d3 = pointToPoint.Install(e4d3);
        NetDeviceContainer c_e5d4 = pointToPoint.Install(e5d4);
        NetDeviceContainer c_e6d5 = pointToPoint.Install(e6d5);
        NetDeviceContainer c_e6d6 = pointToPoint.Install(e6d6);
        NetDeviceContainer c_e2d7 = pointToPoint.Install(e2d7);
        NetDeviceContainer c_e4d8 = pointToPoint.Install(e4d8);

        PointToPointHelper pointToPoint1;
        pointToPoint1.SetDeviceAttribute ("DataRate", StringValue ("10Mbps"));
        pointToPoint1.SetChannelAttribute ("Delay", StringValue ("2ms"));

        NetDeviceContainer c_e1b1 = pointToPoint1.Install(e1b1);
        NetDeviceContainer c_e2b2 = pointToPoint1.Install(e2b2);
        NetDeviceContainer c_e3b3 = pointToPoint1.Install(e3b3);
        NetDeviceContainer c_b6e6 = pointToPoint1.Install(b6e6);
        NetDeviceContainer c_b5e5 = pointToPoint1.Install(b5e5);
        NetDeviceContainer c_b4e4 = pointToPoint1.Install(b4e4);
       
        PointToPointHelper pointToPoint2;
        pointToPoint2.SetDeviceAttribute ("DataRate", StringValue ("1.5Mbps"));
        pointToPoint2.SetChannelAttribute ("Delay", StringValue ("10ms"));
        
        NetDeviceContainer c_b1b2 = pointToPoint2.Install(b1b2);

        PointToPointHelper pointToPoint3;
        pointToPoint3.SetDeviceAttribute ("DataRate", StringValue ("1.5Mbps"));
        pointToPoint3.SetChannelAttribute ("Delay", StringValue ("7.2ms"));
        
        NetDeviceContainer c_b1b7 = pointToPoint3.Install(b1b7);

        PointToPointHelper pointToPoint4;
        pointToPoint4.SetDeviceAttribute ("DataRate", StringValue ("1.2Mbps"));
        pointToPoint4.SetChannelAttribute ("Delay", StringValue ("6.5ms"));
        
        NetDeviceContainer c_b2b7 = pointToPoint4.Install(b2b7);

        PointToPointHelper pointToPoint5;
        pointToPoint5.SetDeviceAttribute ("DataRate", StringValue ("2.8Mbps"));
        pointToPoint5.SetChannelAttribute ("Delay", StringValue ("2.3ms"));
        
        NetDeviceContainer c_b2b8 = pointToPoint5.Install(b2b8);


        PointToPointHelper pointToPoint6;
        pointToPoint6.SetDeviceAttribute ("DataRate", StringValue ("1.5Mbps"));
        pointToPoint6.SetChannelAttribute ("Delay", StringValue ("2.5ms"));
        
        NetDeviceContainer c_b3b8 = pointToPoint6.Install(b3b8);


        PointToPointHelper pointToPoint7;
        pointToPoint7.SetDeviceAttribute ("DataRate", StringValue ("2.5Mbps"));
        pointToPoint7.SetChannelAttribute ("Delay", StringValue ("3.4ms"));
        
        NetDeviceContainer c_b8b7 = pointToPoint7.Install(b8b7);


        PointToPointHelper pointToPoint8;
        pointToPoint8.SetDeviceAttribute ("DataRate", StringValue ("1.5Mbps"));
        pointToPoint8.SetChannelAttribute ("Delay", StringValue ("13.1ms"));
        
        NetDeviceContainer c_b7b6 = pointToPoint8.Install(b7b6);


        PointToPointHelper pointToPoint9;
        pointToPoint9.SetDeviceAttribute ("DataRate", StringValue ("1.5Mbps"));
        pointToPoint9.SetChannelAttribute ("Delay", StringValue ("8.2ms"));
        
        NetDeviceContainer c_b7b5 = pointToPoint9.Install(b7b5);
       


        PointToPointHelper pointToPoint10;
        pointToPoint10.SetDeviceAttribute ("DataRate", StringValue ("1.5Mbps"));
        pointToPoint10.SetChannelAttribute ("Delay", StringValue ("9.2ms"));
        
        NetDeviceContainer c_b8b5 = pointToPoint10.Install(b8b5);


        PointToPointHelper pointToPoint11;
        pointToPoint11.SetDeviceAttribute ("DataRate", StringValue ("3Mbps"));
        pointToPoint11.SetChannelAttribute ("Delay", StringValue ("1.5ms"));
        
        NetDeviceContainer c_b8b4 = pointToPoint11.Install(b8b4);

        PointToPointHelper pointToPoint12;
        pointToPoint12.SetDeviceAttribute ("DataRate", StringValue ("1.5Mbps"));
        pointToPoint12.SetChannelAttribute ("Delay", StringValue ("23ms"));
        
        NetDeviceContainer c_b3b4 = pointToPoint12.Install(b3b4);


        InternetStackHelper stack;
        stack.Install (nodes);

        //assign address
        Ipv4AddressHelper address;
        Ipv4InterfaceContainer a_e1b1;
        Ipv4InterfaceContainer a_e2b2;
        Ipv4InterfaceContainer a_e3b3;
        Ipv4InterfaceContainer a_b6e6;
        Ipv4InterfaceContainer a_b5e5;
        Ipv4InterfaceContainer a_b4e4;
        Ipv4InterfaceContainer a_b1b2;
        Ipv4InterfaceContainer a_b1b7;
        Ipv4InterfaceContainer a_b2b7;
        Ipv4InterfaceContainer a_b2b8;
        Ipv4InterfaceContainer a_b3b8;
        Ipv4InterfaceContainer a_b8b7;
        Ipv4InterfaceContainer a_b7b6;
        Ipv4InterfaceContainer a_b7b5;
        Ipv4InterfaceContainer a_b8b5;
        Ipv4InterfaceContainer a_b8b4;
        Ipv4InterfaceContainer a_b3b4;


        Ipv4InterfaceContainer a_s1e2;
        Ipv4InterfaceContainer a_s2e2;
        Ipv4InterfaceContainer a_s3e1;
        Ipv4InterfaceContainer a_s4e1;
        Ipv4InterfaceContainer a_s5e3;
        Ipv4InterfaceContainer a_s6e2;
        Ipv4InterfaceContainer a_s7e1;
        Ipv4InterfaceContainer a_s8e3;
        Ipv4InterfaceContainer a_e4d1;
        Ipv4InterfaceContainer a_e5d2;
        Ipv4InterfaceContainer a_e4d3;
        Ipv4InterfaceContainer a_e5d4;
        Ipv4InterfaceContainer a_e6d5;
        Ipv4InterfaceContainer a_e6d6;
        Ipv4InterfaceContainer a_e2d7;
        Ipv4InterfaceContainer a_e4d8;



       address.SetBase ("10.1.1.0", "255.255.255.0");
        a_e1b1 = address.Assign(c_e1b1);

        address.SetBase ("10.1.2.0", "255.255.255.0");
        a_e2b2 = address.Assign(c_e2b2);


         address.SetBase ("10.1.3.0", "255.255.255.0");
        a_e3b3 = address.Assign(c_e3b3);


        address.SetBase ("10.1.4.0", "255.255.255.0");
        a_b6e6 = address.Assign(c_b6e6);

        address.SetBase ("10.1.5.0", "255.255.255.0");
        a_b5e5 = address.Assign(c_b5e5);


         address.SetBase ("10.1.6.0", "255.255.255.0");
        a_b4e4 = address.Assign(c_b4e4);

        address.SetBase ("10.1.7.0", "255.255.255.0");
        a_b1b2 = address.Assign(c_b1b2);

        address.SetBase ("10.1.8.0", "255.255.255.0");
        a_b1b7 = address.Assign(c_b1b7);


         address.SetBase ("10.1.9.0", "255.255.255.0");
        a_b2b7 = address.Assign(c_b2b7);

        address.SetBase ("10.1.10.0", "255.255.255.0");
        a_b2b8 = address.Assign(c_b2b8);

        address.SetBase ("10.1.11.0", "255.255.255.0");
        a_b3b8 = address.Assign(c_b3b8);


         address.SetBase ("10.1.12.0", "255.255.255.0");
        a_b8b7 = address.Assign(c_b8b7);

        address.SetBase ("10.1.13.0", "255.255.255.0");
        a_b7b6 = address.Assign(c_b7b6);

        address.SetBase ("10.1.14.0", "255.255.255.0");
        a_b7b5 = address.Assign(c_b7b5);


         address.SetBase ("10.1.15.0", "255.255.255.0");
         a_b8b5 = address.Assign(c_b8b5);

        address.SetBase ("10.1.16.0", "255.255.255.0");
        a_b8b4 = address.Assign(c_b8b4);

        address.SetBase ("10.1.17.0", "255.255.255.0");
        a_b3b4 = address.Assign(c_b3b4);


        address.SetBase ("10.1.18.0", "255.255.255.0");
        a_s1e2 = address.Assign(c_s1e2);

        address.SetBase ("10.1.19.0", "255.255.255.0");
        a_s2e2 = address.Assign(c_s2e2);

        address.SetBase ("10.1.20.0", "255.255.255.0");
        a_s3e1 = address.Assign(c_s3e1);

        address.SetBase ("10.1.21.0", "255.255.255.0");
        a_s4e1 = address.Assign(c_s4e1);

        address.SetBase ("10.1.22.0", "255.255.255.0");
        a_s5e3 = address.Assign(c_s5e3);

        address.SetBase ("10.1.23.0", "255.255.255.0");
        a_s6e2 = address.Assign(c_s6e2);

        address.SetBase ("10.1.24.0", "255.255.255.0");
        a_s7e1 = address.Assign(c_s7e1);

        address.SetBase ("10.1.25.0", "255.255.255.0");
        a_s8e3 = address.Assign(c_s8e3);

        address.SetBase ("10.1.26.0", "255.255.255.0");
        a_e4d1 = address.Assign(c_e4d1);

        address.SetBase ("10.1.27.0", "255.255.255.0");
        a_e5d2 = address.Assign(c_e5d2);

        address.SetBase ("10.1.28.0", "255.255.255.0");
        a_e4d3 = address.Assign(c_e4d3);

        address.SetBase ("10.1.29.0", "255.255.255.0");
        a_e5d4 = address.Assign(c_e5d4);


        address.SetBase ("10.1.30.0", "255.255.255.0");
        a_e6d5 = address.Assign(c_e6d5);

        address.SetBase ("10.1.31.0", "255.255.255.0");
        a_e6d6 = address.Assign(c_e6d6);

        address.SetBase ("10.1.32.0", "255.255.255.0");
        a_e2d7 = address.Assign(c_e2d7);

        address.SetBase ("10.1.33.0", "255.255.255.0");
        a_e4d8 = address.Assign(c_e4d8);



        //generate routing table
        Ipv4GlobalRoutingHelper::PopulateRoutingTables ();

        //sink deploy
        uint16_t port1 = 1;
        uint16_t port2 = 2;
        uint16_t port3 = 3;
        uint16_t port4 = 4;
        uint16_t port5 = 5;
        uint16_t port6 = 6;
        uint16_t port7 = 7;
        uint16_t port8 = 8;

        PacketSinkHelper sink1("ns3::TcpSocketFactory", InetSocketAddress(Ipv4Address::GetAny(), port1));
        PacketSinkHelper sink2("ns3::TcpSocketFactory", InetSocketAddress(Ipv4Address::GetAny(), port2));
        PacketSinkHelper sink3("ns3::TcpSocketFactory", InetSocketAddress(Ipv4Address::GetAny(), port3));
        PacketSinkHelper sink4("ns3::TcpSocketFactory", InetSocketAddress(Ipv4Address::GetAny(), port4));
        PacketSinkHelper sink5("ns3::TcpSocketFactory", InetSocketAddress(Ipv4Address::GetAny(), port5));
        PacketSinkHelper sink6("ns3::TcpSocketFactory", InetSocketAddress(Ipv4Address::GetAny(), port6));
        PacketSinkHelper sink7("ns3::TcpSocketFactory", InetSocketAddress(Ipv4Address::GetAny(), port7));
        PacketSinkHelper sink8("ns3::TcpSocketFactory", InetSocketAddress(Ipv4Address::GetAny(), port8));
        
        ApplicationContainer sinkApps1 = sink1.Install(nodes.Get(8));
        ApplicationContainer sinkApps2 = sink2.Install(nodes.Get(9));
        ApplicationContainer sinkApps3 = sink3.Install(nodes.Get(10));
        ApplicationContainer sinkApps4 = sink4.Install(nodes.Get(11));
        ApplicationContainer sinkApps5 = sink5.Install(nodes.Get(12));
        ApplicationContainer sinkApps6 = sink6.Install(nodes.Get(13));
        ApplicationContainer sinkApps7 = sink7.Install(nodes.Get(14));
        ApplicationContainer sinkApps8 = sink8.Install(nodes.Get(15));
      
        sinkApps1.Start(Seconds(0.0));
        sinkApps1.Stop(Seconds(30.0));

        sinkApps2.Start(Seconds(0.0));
        sinkApps2.Stop(Seconds(30.0));

        sinkApps3.Start(Seconds(0.0));
        sinkApps3.Stop(Seconds(30.0));

        sinkApps4.Start(Seconds(0.0));
        sinkApps4.Stop(Seconds(30.0));
        
        sinkApps5.Start(Seconds(0.0));
        sinkApps5.Stop(Seconds(30.0));

        sinkApps6.Start(Seconds(0.0));
        sinkApps6.Stop(Seconds(30.0));

        sinkApps7.Start(Seconds(0.0));
        sinkApps7.Stop(Seconds(30.0));

        sinkApps8.Start(Seconds(0.0));
        sinkApps8.Stop(Seconds(30.0));

       

        //flow 
        BulkSendHelper source1("ns3::TcpSocketFactory", InetSocketAddress(Ipv4Address(a_e4d1.GetAddress(1)), port1));
        BulkSendHelper source2("ns3::TcpSocketFactory", InetSocketAddress(Ipv4Address(a_e5d2.GetAddress(1)), port2));
        BulkSendHelper source3("ns3::TcpSocketFactory", InetSocketAddress(Ipv4Address(a_e4d3.GetAddress(1)), port3));
        BulkSendHelper source4("ns3::TcpSocketFactory", InetSocketAddress(Ipv4Address(a_e5d4.GetAddress(1)), port4));
        BulkSendHelper source5("ns3::TcpSocketFactory", InetSocketAddress(Ipv4Address(a_e6d5.GetAddress(1)), port5));
        BulkSendHelper source6("ns3::TcpSocketFactory", InetSocketAddress(Ipv4Address(a_e6d6.GetAddress(1)), port6));
        BulkSendHelper source7("ns3::TcpSocketFactory", InetSocketAddress(Ipv4Address(a_e2d7.GetAddress(1)), port7));
        BulkSendHelper source8("ns3::TcpSocketFactory", InetSocketAddress(Ipv4Address(a_e4d8.GetAddress(1)), port8));



        source1.SetAttribute("MaxBytes", UintegerValue(0));
        source2.SetAttribute("MaxBytes", UintegerValue(0));
        source3.SetAttribute("MaxBytes", UintegerValue(0));
        source4.SetAttribute("MaxBytes", UintegerValue(0));
        source5.SetAttribute("MaxBytes", UintegerValue(0));
        source6.SetAttribute("MaxBytes", UintegerValue(0));
        source7.SetAttribute("MaxBytes", UintegerValue(0));
        source8.SetAttribute("MaxBytes", UintegerValue(0));
        

      
        ApplicationContainer sourceApps1 = source1.Install(nodes.Get(0));
        ApplicationContainer sourceApps2 = source2.Install(nodes.Get(1));
        ApplicationContainer sourceApps3 = source3.Install(nodes.Get(2));
        ApplicationContainer sourceApps4 = source4.Install(nodes.Get(3));
        ApplicationContainer sourceApps5 = source5.Install(nodes.Get(4));
        ApplicationContainer sourceApps6 = source6.Install(nodes.Get(5));
        ApplicationContainer sourceApps7 = source7.Install(nodes.Get(6));
        ApplicationContainer sourceApps8 = source8.Install(nodes.Get(7));

        sourceApps1.Start(Seconds(0.0));
        sourceApps1.Stop(Seconds(30.0));
        
        sourceApps2.Start(Seconds(0.0));
        sourceApps2.Stop(Seconds(30.0));

        sourceApps3.Start(Seconds(0.0));
        sourceApps3.Stop(Seconds(30.0));

        sourceApps4.Start(Seconds(0.0));
        sourceApps4.Stop(Seconds(30.0));

        sourceApps5.Start(Seconds(0.0));
        sourceApps5.Stop(Seconds(30.0));

        sourceApps6.Start(Seconds(0.0));
        sourceApps6.Stop(Seconds(30.0));

        sourceApps7.Start(Seconds(0.0));
        sourceApps7.Stop(Seconds(30.0));

        sourceApps8.Start(Seconds(0.0));
        sourceApps8.Stop(Seconds(30.0));



        //animation generate
        MobilityHelper MH;
        MH.SetMobilityModel("ns3::ConstantPositionMobilityModel");
        MH.Install(nodes);

        AnimationInterface anim ("project1Anim.xml");                   // output .xml name
        //max packets number for one animation file
        anim.SetMaxPktsPerTraceFile(5000000);
        //Convert the node to animation type
        Ptr<ConstantPositionMobilityModel> s1 = nodes.Get(0)->GetObject<ConstantPositionMobilityModel>();
        Ptr<ConstantPositionMobilityModel> s2 = nodes.Get(1)->GetObject<ConstantPositionMobilityModel>();
        Ptr<ConstantPositionMobilityModel> s3 = nodes.Get(2)->GetObject<ConstantPositionMobilityModel>();
        Ptr<ConstantPositionMobilityModel> s4 = nodes.Get(3)->GetObject<ConstantPositionMobilityModel>(); 
        Ptr<ConstantPositionMobilityModel> s5 = nodes.Get(4)->GetObject<ConstantPositionMobilityModel>();
        Ptr<ConstantPositionMobilityModel> s6 = nodes.Get(5)->GetObject<ConstantPositionMobilityModel>();
        Ptr<ConstantPositionMobilityModel> s7 = nodes.Get(6)->GetObject<ConstantPositionMobilityModel>(); 
        Ptr<ConstantPositionMobilityModel> s8 = nodes.Get(7)->GetObject<ConstantPositionMobilityModel>();
        Ptr<ConstantPositionMobilityModel> d1 = nodes.Get(8)->GetObject<ConstantPositionMobilityModel>();
        Ptr<ConstantPositionMobilityModel> d2 = nodes.Get(9)->GetObject<ConstantPositionMobilityModel>(); 
        Ptr<ConstantPositionMobilityModel> d3 = nodes.Get(10)->GetObject<ConstantPositionMobilityModel>();
        Ptr<ConstantPositionMobilityModel> d4 = nodes.Get(11)->GetObject<ConstantPositionMobilityModel>();
        Ptr<ConstantPositionMobilityModel> d5 = nodes.Get(12)->GetObject<ConstantPositionMobilityModel>();  
        Ptr<ConstantPositionMobilityModel> d6 = nodes.Get(13)->GetObject<ConstantPositionMobilityModel>();
        Ptr<ConstantPositionMobilityModel> d7 = nodes.Get(14)->GetObject<ConstantPositionMobilityModel>();
        Ptr<ConstantPositionMobilityModel> d8 = nodes.Get(15)->GetObject<ConstantPositionMobilityModel>(); 
        Ptr<ConstantPositionMobilityModel> e1 = nodes.Get(16)->GetObject<ConstantPositionMobilityModel>();
        Ptr<ConstantPositionMobilityModel> e2 = nodes.Get(17)->GetObject<ConstantPositionMobilityModel>();
        Ptr<ConstantPositionMobilityModel> e3 = nodes.Get(18)->GetObject<ConstantPositionMobilityModel>(); 
        Ptr<ConstantPositionMobilityModel> e4 = nodes.Get(19)->GetObject<ConstantPositionMobilityModel>();
        Ptr<ConstantPositionMobilityModel> e5 = nodes.Get(20)->GetObject<ConstantPositionMobilityModel>();
        Ptr<ConstantPositionMobilityModel> e6 = nodes.Get(21)->GetObject<ConstantPositionMobilityModel>(); 
        Ptr<ConstantPositionMobilityModel> b1 = nodes.Get(22)->GetObject<ConstantPositionMobilityModel>();
        Ptr<ConstantPositionMobilityModel> b2 = nodes.Get(23)->GetObject<ConstantPositionMobilityModel>();
        Ptr<ConstantPositionMobilityModel> b3 = nodes.Get(24)->GetObject<ConstantPositionMobilityModel>(); 
        Ptr<ConstantPositionMobilityModel> b4 = nodes.Get(25)->GetObject<ConstantPositionMobilityModel>();
        Ptr<ConstantPositionMobilityModel> b5 = nodes.Get(26)->GetObject<ConstantPositionMobilityModel>();
        Ptr<ConstantPositionMobilityModel> b6 = nodes.Get(27)->GetObject<ConstantPositionMobilityModel>(); 
        Ptr<ConstantPositionMobilityModel> b7 = nodes.Get(28)->GetObject<ConstantPositionMobilityModel>();
        Ptr<ConstantPositionMobilityModel> b8 = nodes.Get(29)->GetObject<ConstantPositionMobilityModel>();
       
       
       

        //Set the position of each node
        s1->SetPosition(Vector(68,1,0));
        s2->SetPosition(Vector(76,7,0));  
        s3->SetPosition(Vector(0,3,0)); 
        s4->SetPosition(Vector(5,0,0));
        s5->SetPosition(Vector(84,41,0));
        s6->SetPosition(Vector(77,16,0)); 
        s7->SetPosition(Vector(12,0,0));
        s8->SetPosition(Vector(84,53,0));  
        d1->SetPosition(Vector(50,77,0));
        d2->SetPosition(Vector(12,76,0));
        d3->SetPosition(Vector(60,80,0)); 
        d4->SetPosition(Vector(24,76,0));
        d5->SetPosition(Vector(0,39,0));
        d6->SetPosition(Vector(0,50,0));  
        d7->SetPosition(Vector(58,0,0));
        d8->SetPosition(Vector(70,78,0));
        e1->SetPosition(Vector(10,12,0)); 
        e2->SetPosition(Vector(56,17,0));
        e3->SetPosition(Vector(72,46,0));
        e4->SetPosition(Vector(61,72,0));  
        e5->SetPosition(Vector(19,68,0));
        e6->SetPosition(Vector(8,45,0));
        b1->SetPosition(Vector(23,23,0));   
        b2->SetPosition(Vector(50,23,0));  
        b3->SetPosition(Vector(59,46,0));
        b4->SetPosition(Vector(57,63,0));
        b5->SetPosition(Vector(24,60,0));  
        b6->SetPosition(Vector(18,45,0));  
        b7->SetPosition(Vector(31,45,0));
        b8->SetPosition(Vector(51,46,0));
   
	// anim.SetConstantPosition(nodes.Get(0),5.0, 20.0);       // node number, x-value, y-value
	// anim.SetConstantPosition(nodes.Get(1),35.0, 20.0);
	// anim.SetConstantPosition(nodes.Get(2),65.0, 20.0);

  Simulator::Schedule(Seconds(30), &averageThroughput);
	        monitor = flowmon.InstallAll ();

	
  Simulator::Stop (Seconds (30));
  Simulator::Run ();
  Simulator::Destroy ();
  return 0;
}
