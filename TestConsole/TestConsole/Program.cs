using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Net;
using System.Net.Sockets;
using System.IO;

namespace TestConsole
{
    class CNetworkTest
    {
        private Socket m_server;
        private Socket m_client;

        private void ServerOpen()
        {
            m_server = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
            IPEndPoint ipep = new IPEndPoint(IPAddress.Any, 9999);
            m_server.Bind(ipep);
            m_server.Listen(5);

            Console.WriteLine("클라이언트의 연결을 대기");
        }

        private void ClientOpen()
        {
            m_client = m_server.Accept();
            for ( int i = 0 ; i < 10 ; ++i )
            {
                string str = Console.ReadLine();
                Writer(str);
            }
        } 

        private void Writer(string str)
        {
            NetworkStream stream = new NetworkStream(m_client);
            StreamWriter writer = new StreamWriter(stream);

            writer.WriteLine(str);
            writer.Flush();
        }

        static void Main(string[] args)
        {
            CNetworkTest test = new CNetworkTest();
            test.ServerOpen();
            test.ClientOpen();
            Console.WriteLine("Hellow World");
        }
    }
}
