#include <QCoreApplication>
#include "Servicios.h"
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/server/TSimpleServer.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/TBufferTransports.h>
#include <iostream>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlResult>
#include <QtSql/QSqlQuery>

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;

using namespace std;
using namespace  ::Thrift;

class ServiciosHandler : virtual public ServiciosIf {
 public:
  ServiciosHandler() {
    // Your initialization goes here
  }

  bool validarCredenciales(const std::string& usuario, const std::string& contrasena) {
      printf("validarCredenciales\n");
      QSqlQuery query;
      query.prepare("SELECT usuario, contrasena FROM usuarioclienteescritorio WHERE usuario = :usu");
      QString aux = QString::fromStdString(usuario);
      query.bindValue(":usu",aux);
      query.exec();
      if(query.size()>0){
          query.next();
          if(query.value(1).toString().toStdString().compare(contrasena)==0){
              return true;
          }
      }
      return false;
  }

  void registrarUsuario(const UsuarioClienteEscritorio& usuario) {
    // Your implementation goes here
      QSqlQuery query;
      query.prepare("INSERT INTO usuarioclienteescritorio "
                    "(idUsuario, nombre, cargo, usuario, contrasena) "
                    "VALUES (NULL, :nom, :car, :usu, :con)");
      QString nombre = QString::fromStdString(usuario.nombre);
      query.bindValue(":nom",nombre);
      QString cargo = QString::fromStdString(usuario.cargo);
      query.bindValue(":car",cargo);
      QString usua = QString::fromStdString(usuario.usuario);
      query.bindValue(":usu",usua);
      QString contrasena = QString::fromStdString(usuario.contrasena);
      query.bindValue(":con",contrasena);
      query.exec();
    printf("registrarUsuario\n");
  }

  void recuperarIncidentes(std::vector<Incidente> & _return) {
      // Your implementation goes here
        QSqlQuery query("SELECT idIncidente, ciudad, fecha, hora, estado FROM incidente");
        while (query.next())
        {
            Incidente in;
            in.__set_idIncidente(query.value(0).toInt());
            in.__set_ciudad(query.value(1).toString().toStdString());
            in.__set_fecha(query.value(2).toString().toStdString());
            in.__set_hora(query.value(3).toInt());
            in.__set_estado(query.value(4).toInt());
            _return.push_back(in);
        }
    printf("recuperarIncidentes\n");
  }

  void recuperarReportes(std::vector<Reporte> & _return, const int32_t idIncidente) {
      QSqlQuery query;
      query.prepare("SELECT idReporte, latitud, longitud, nombreConductor, "
                    "marca, modelo, color, nombreAseguradora, numPoliza, placa, "
                    "idConductor, idVehiculo, idIncidente FROM reporte "
                    "WHERE idIncidente = :id");
      query.bindValue(":id", idIncidente);
      query.exec();
      while (query.next())
      {
          Reporte r;
          r.__set_idReporte(query.value(0).toInt());
          r.__set_latitud(query.value(1).toDouble());
          r.__set_longitud(query.value(2).toDouble());
          r.__set_nombreConductor(query.value(3).toString().toStdString());
          r.__set_marca(query.value(4).toString().toStdString());
          r.__set_modelo(query.value(5).toString().toStdString());
          r.__set_color(query.value(6).toString().toStdString());
          r.__set_nombreAseguradora(query.value(7).toString().toStdString());
          r.__set_numPoliza(query.value(8).toString().toStdString());
          r.__set_placa(query.value(9).toString().toStdString());
          r.__set_idConductor(query.value(10).toInt());
          r.__set_idVehiculo(query.value(11).toInt());
          r.__set_idIncidente(idIncidente);
          _return.push_back(r);
      }
    printf("recuperarReportes\n");
  }

  void recuperarVehiculoInvolucrado(Vehiculo& _return, const int32_t idVehiculo) {
      QSqlQuery query;
      query.prepare("SELECT idVehiculo, marca, modelo, anio, color, nombreAseguradora, numPoliza, placa "
                    "FROM vehiculo WHERE idVehiculo = :id");
      query.bindValue(":id",idVehiculo);
      query.exec();
      if (query.size()>0)
      {
          query.next();
          _return.__set_idVehiculo(query.value(0).toInt());
          _return.__set_marca(query.value(1).toString().toStdString());
          _return.__set_modelo(query.value(2).toString().toStdString());
          _return.__set_anio(query.value(3).toInt());
          _return.__set_color(query.value(4).toString().toStdString());
          _return.__set_nombreAseguradora(query.value(5).toString().toStdString());
          _return.__set_numPoliza(query.value(6).toString().toStdString());
          _return.__set_placa(query.value(7).toString().toStdString());
      }
    printf("recuperarVehiculoInvolucrado\n");
  }

  void recuperarConductorInvolucrado(Conductor& _return, const int32_t idConductor) {
      QSqlQuery query;
      query.prepare("SELECT idConductor, nombre, fechaNacimiento, numLicencia, telefono "
                    "FROM conductor WHERE idConductor = :id");
      query.bindValue(":id",idConductor);
      query.exec();
      if (query.size()>0)
      {
          query.next();
          _return.__set_idConductor(query.value(0).toInt());
          _return.__set_nombre(query.value(1).toString().toStdString());
          _return.__set_fechaNacimiento(query.value(2).toString().toStdString());
          _return.__set_numLicencia(query.value(3).toString().toStdString());
          _return.__set_telefono(query.value(4).toString().toStdString());
      }
    printf("recuperarConductorInvolucrado\n");
  }

  void recuperarFotosReportadas(std::vector<Foto> & _return, const int32_t idReporte) {
      QSqlQuery query;
      query.prepare("SELECT idFoto, idReporte, foto1 FROM foto WHERE idReporte = :id");
      query.bindValue(":id", idReporte);
      query.exec();
      while (query.next())
      {
          Foto f;
          f.__set_idFoto(query.value(0).toInt());
          f.__set_idReporte(query.value(1).toInt());
          f.__set_foto(query.value(2).toString().toStdString());
          _return.push_back(f);
      }
    printf("recuperarFotosReportadas\n");
  }

  void dictaminarIncidente(const Dictamen& dic) {
    QSqlQuery query;
    query.prepare("INSERT INTO dictamen (idDictamen, "
                  "folio, descripcion, fechaHora, idIncidente, "
                  "idUsuarioClienteEscritorio) VALUES (NULL,:f,:d,NOW(),:ii,:iu)");
    QString aux = QString::fromStdString(dic.folio);
    query.bindValue(":f",aux);
    aux = QString::fromStdString(dic.descripcion);
    query.bindValue(":d",aux);
    query.bindValue(":ii",dic.idIncidente);
    query.bindValue(":iu",dic.idUsuario);
    query.exec();
    QSqlQuery query2;
    query2.prepare("UPDATE incidente set estado = 1 WHERE idIncidente = :id");
    query2.bindValue(":id",dic.idIncidente);
    query2.exec();
    printf("dictaminarIncidente\n");
  }

  bool validarUsuario(const std::string& usuario) {
    printf("validarUsuario\n");
    QSqlQuery query;
    query.prepare("SELECT usuario FROM usuarioclienteescritorio WHERE usuario = :usu");
    QString aux = QString::fromStdString(usuario);
    query.bindValue(":usu",aux);
    query.exec();
    if(query.size()==0){
        return true;
    } else {
        return false;
    }
  }

  bool validarFolio(const std::string& folio) {
    printf("validarFolio\n");
    QSqlQuery query;
    query.prepare("SELECT folio FROM dictamen WHERE folio = :fol");
    QString aux = QString::fromStdString(folio);
    query.bindValue(":fol",aux);
    query.exec();
    if(query.size()==0){
        return true;
    } else {
        return false;
    }
  }

  void recuperarUsuario(UsuarioClienteEscritorio& _return, const std::string& usuario) {
      printf("recuperarUsuario\n");
      QSqlQuery query;
      query.prepare("SELECT idUsuario, nombre, cargo, usuario, contrasena FROM usuarioclienteescritorio WHERE usuario = :usu");
      QString aux = QString::fromStdString(usuario);
      query.bindValue(":usu",aux);
      query.exec();
      if (query.size()>0)
      {
          query.next();
            _return.__set_idUsuario(query.value(0).toInt());
            _return.__set_nombre(query.value(1).toString().toStdString());
            _return.__set_cargo(query.value(2).toString().toStdString());
            _return.__set_usuario(usuario);
            _return.__set_contrasena(query.value(4).toString().toStdString());
      }
  }

  void actualizarContrasena(const int32_t idUsuario, const std::string& contrasena) {
      QSqlQuery query;
      query.prepare("UPDATE usuarioclienteescritorio SET contrasena = :co WHERE idUsuario = :id");
      QString aux = QString::fromStdString(contrasena);
      query.bindValue(":co", aux);
      query.bindValue(":id",idUsuario);
      query.exec();
    printf("actualizarContrasena\n");
  }

};

int main(int argc, char **argv) {

    QSqlDatabase mDatabase;

    mDatabase = QSqlDatabase::addDatabase("QMYSQL");
    mDatabase.setHostName("localhost");
    mDatabase.setPort(3306);
    mDatabase.setDatabaseName("transito");
    mDatabase.setUserName("root");
    mDatabase.setPassword("1995_Foncho");
    if(!mDatabase.open()){
        printf("Error en la base\n");
        return 0;
    }
    printf("Conexión con base de datos exitosa\n");
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
