// This autogenerated skeleton file illustrates how to build a server.
// You should copy it to another filename to avoid overwriting it.
/*
#include "Servicios.h"
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/server/TSimpleServer.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/TBufferTransports.h>

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;

using namespace  ::Thrift;

class ServiciosHandler : virtual public ServiciosIf {
 public:
  ServiciosHandler() {
    // Your initialization goes here
  }

  bool validarCredenciales(const std::string& usuario, const std::string& contrasena) {
    // Your implementation goes here
    printf("validarCredenciales\n");
  }

  void registrarUsuario(const UsuarioClienteEscritorio& usuario) {
    // Your implementation goes here
    printf("registrarUsuario\n");
  }

  void recuperarIncidentes(std::vector<Incidente> & _return) {
    // Your implementation goes here
    printf("recuperarIncidentes\n");
  }

  void recuperarReportes(std::vector<Reporte> & _return, const int32_t idIncidente) {
    // Your implementation goes here
    printf("recuperarReportes\n");
  }

  void recuperarVehiculoInvolucrado(Vehiculo& _return, const int32_t idVehiculo) {
    // Your implementation goes here
    printf("recuperarVehiculoInvolucrado\n");
  }

  void recuperarConductorInvolucrado(Conductor& _return, const int32_t idConductor) {
    // Your implementation goes here
    printf("recuperarConductorInvolucrado\n");
  }

  void recuperarFotosReportadas(std::vector<Foto> & _return, const int32_t idReporte) {
    // Your implementation goes here
    printf("recuperarFotosReportadas\n");
  }

  void dictaminarIncidente(const Dictamen& dic) {
    // Your implementation goes here
    printf("dictaminarIncidente\n");
  }

  bool validarUsuario(const std::string& usuario) {
    // Your implementation goes here
    printf("validarUsuario\n");
  }

  bool validarFolio(const std::string& folio) {
    // Your implementation goes here
    printf("validarFolio\n");
  }

  void recuperarUsuario(UsuarioClienteEscritorio& _return, const std::string& usuario) {
    // Your implementation goes here
    printf("recuperarUsuario\n");
  }

  void actualizarContrasena(const int32_t idUsuario, const std::string& contrasena) {
    // Your implementation goes here
    printf("actualizarContrasena\n");
  }

};

int main(int argc, char **argv) {
  int port = 9090;
  ::apache::thrift::stdcxx::shared_ptr<ServiciosHandler> handler(new ServiciosHandler());
  ::apache::thrift::stdcxx::shared_ptr<TProcessor> processor(new ServiciosProcessor(handler));
  ::apache::thrift::stdcxx::shared_ptr<TServerTransport> serverTransport(new TServerSocket(port));
  ::apache::thrift::stdcxx::shared_ptr<TTransportFactory> transportFactory(new TBufferedTransportFactory());
  ::apache::thrift::stdcxx::shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());

  TSimpleServer server(processor, serverTransport, transportFactory, protocolFactory);
  server.serve();
  return 0;
}
*/
