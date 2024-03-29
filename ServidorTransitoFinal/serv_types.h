/**
 * Autogenerated by Thrift Compiler (0.12.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef serv_TYPES_H
#define serv_TYPES_H

#include <iosfwd>

#include <thrift/Thrift.h>
#include <thrift/TApplicationException.h>
#include <thrift/TBase.h>
#include <thrift/protocol/TProtocol.h>
#include <thrift/transport/TTransport.h>

#include <thrift/stdcxx.h>


namespace Thrift {

class UsuarioClienteEscritorio;

class Dictamen;

class Incidente;

class Conductor;

class Reporte;

class Foto;

class Vehiculo;

class VehiculoConductor;

typedef struct _UsuarioClienteEscritorio__isset {
  _UsuarioClienteEscritorio__isset() : idUsuario(false), nombre(false), cargo(false), usuario(false), contrasena(false), token(false) {}
  bool idUsuario :1;
  bool nombre :1;
  bool cargo :1;
  bool usuario :1;
  bool contrasena :1;
  bool token :1;
} _UsuarioClienteEscritorio__isset;

class UsuarioClienteEscritorio : public virtual ::apache::thrift::TBase {
 public:

  UsuarioClienteEscritorio(const UsuarioClienteEscritorio&);
  UsuarioClienteEscritorio& operator=(const UsuarioClienteEscritorio&);
  UsuarioClienteEscritorio() : idUsuario(0), nombre(), cargo(), usuario(), contrasena(), token() {
  }

  virtual ~UsuarioClienteEscritorio() throw();
  int32_t idUsuario;
  std::string nombre;
  std::string cargo;
  std::string usuario;
  std::string contrasena;
  std::string token;

  _UsuarioClienteEscritorio__isset __isset;

  void __set_idUsuario(const int32_t val);

  void __set_nombre(const std::string& val);

  void __set_cargo(const std::string& val);

  void __set_usuario(const std::string& val);

  void __set_contrasena(const std::string& val);

  void __set_token(const std::string& val);

  bool operator == (const UsuarioClienteEscritorio & rhs) const
  {
    if (!(idUsuario == rhs.idUsuario))
      return false;
    if (!(nombre == rhs.nombre))
      return false;
    if (!(cargo == rhs.cargo))
      return false;
    if (!(usuario == rhs.usuario))
      return false;
    if (!(contrasena == rhs.contrasena))
      return false;
    if (!(token == rhs.token))
      return false;
    return true;
  }
  bool operator != (const UsuarioClienteEscritorio &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const UsuarioClienteEscritorio & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(UsuarioClienteEscritorio &a, UsuarioClienteEscritorio &b);

std::ostream& operator<<(std::ostream& out, const UsuarioClienteEscritorio& obj);

typedef struct _Dictamen__isset {
  _Dictamen__isset() : idDictamen(false), folio(false), descripcion(false), fechaHora(false), idIncidente(false), idUsuario(false) {}
  bool idDictamen :1;
  bool folio :1;
  bool descripcion :1;
  bool fechaHora :1;
  bool idIncidente :1;
  bool idUsuario :1;
} _Dictamen__isset;

class Dictamen : public virtual ::apache::thrift::TBase {
 public:

  Dictamen(const Dictamen&);
  Dictamen& operator=(const Dictamen&);
  Dictamen() : idDictamen(0), folio(), descripcion(), fechaHora(), idIncidente(0), idUsuario(0) {
  }

  virtual ~Dictamen() throw();
  int32_t idDictamen;
  std::string folio;
  std::string descripcion;
  std::string fechaHora;
  int32_t idIncidente;
  int32_t idUsuario;

  _Dictamen__isset __isset;

  void __set_idDictamen(const int32_t val);

  void __set_folio(const std::string& val);

  void __set_descripcion(const std::string& val);

  void __set_fechaHora(const std::string& val);

  void __set_idIncidente(const int32_t val);

  void __set_idUsuario(const int32_t val);

  bool operator == (const Dictamen & rhs) const
  {
    if (!(idDictamen == rhs.idDictamen))
      return false;
    if (!(folio == rhs.folio))
      return false;
    if (!(descripcion == rhs.descripcion))
      return false;
    if (!(fechaHora == rhs.fechaHora))
      return false;
    if (!(idIncidente == rhs.idIncidente))
      return false;
    if (!(idUsuario == rhs.idUsuario))
      return false;
    return true;
  }
  bool operator != (const Dictamen &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Dictamen & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(Dictamen &a, Dictamen &b);

std::ostream& operator<<(std::ostream& out, const Dictamen& obj);

typedef struct _Incidente__isset {
  _Incidente__isset() : idIncidente(false), ciudad(false), fecha(false), hora(false), estado(false) {}
  bool idIncidente :1;
  bool ciudad :1;
  bool fecha :1;
  bool hora :1;
  bool estado :1;
} _Incidente__isset;

class Incidente : public virtual ::apache::thrift::TBase {
 public:

  Incidente(const Incidente&);
  Incidente& operator=(const Incidente&);
  Incidente() : idIncidente(0), ciudad(), fecha(), hora(0), estado(0) {
  }

  virtual ~Incidente() throw();
  int32_t idIncidente;
  std::string ciudad;
  std::string fecha;
  int32_t hora;
  int32_t estado;

  _Incidente__isset __isset;

  void __set_idIncidente(const int32_t val);

  void __set_ciudad(const std::string& val);

  void __set_fecha(const std::string& val);

  void __set_hora(const int32_t val);

  void __set_estado(const int32_t val);

  bool operator == (const Incidente & rhs) const
  {
    if (!(idIncidente == rhs.idIncidente))
      return false;
    if (!(ciudad == rhs.ciudad))
      return false;
    if (!(fecha == rhs.fecha))
      return false;
    if (!(hora == rhs.hora))
      return false;
    if (!(estado == rhs.estado))
      return false;
    return true;
  }
  bool operator != (const Incidente &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Incidente & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(Incidente &a, Incidente &b);

std::ostream& operator<<(std::ostream& out, const Incidente& obj);

typedef struct _Conductor__isset {
  _Conductor__isset() : idConductor(false), nombre(false), fechaNacimiento(false), numLicencia(false), telefono(false), contrasena(false), token(false) {}
  bool idConductor :1;
  bool nombre :1;
  bool fechaNacimiento :1;
  bool numLicencia :1;
  bool telefono :1;
  bool contrasena :1;
  bool token :1;
} _Conductor__isset;

class Conductor : public virtual ::apache::thrift::TBase {
 public:

  Conductor(const Conductor&);
  Conductor& operator=(const Conductor&);
  Conductor() : idConductor(0), nombre(), fechaNacimiento(), numLicencia(), telefono(), contrasena(), token() {
  }

  virtual ~Conductor() throw();
  int32_t idConductor;
  std::string nombre;
  std::string fechaNacimiento;
  std::string numLicencia;
  std::string telefono;
  std::string contrasena;
  std::string token;

  _Conductor__isset __isset;

  void __set_idConductor(const int32_t val);

  void __set_nombre(const std::string& val);

  void __set_fechaNacimiento(const std::string& val);

  void __set_numLicencia(const std::string& val);

  void __set_telefono(const std::string& val);

  void __set_contrasena(const std::string& val);

  void __set_token(const std::string& val);

  bool operator == (const Conductor & rhs) const
  {
    if (!(idConductor == rhs.idConductor))
      return false;
    if (!(nombre == rhs.nombre))
      return false;
    if (!(fechaNacimiento == rhs.fechaNacimiento))
      return false;
    if (!(numLicencia == rhs.numLicencia))
      return false;
    if (!(telefono == rhs.telefono))
      return false;
    if (!(contrasena == rhs.contrasena))
      return false;
    if (!(token == rhs.token))
      return false;
    return true;
  }
  bool operator != (const Conductor &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Conductor & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(Conductor &a, Conductor &b);

std::ostream& operator<<(std::ostream& out, const Conductor& obj);

typedef struct _Reporte__isset {
  _Reporte__isset() : idReporte(false), latitud(false), longitud(false), nombreConductor(false), nombreAseguradora(false), numPoliza(false), marca(false), modelo(false), color(false), placa(false), fechaHora(false), idConductor(false), idVehiculo(false), idIncidente(false) {}
  bool idReporte :1;
  bool latitud :1;
  bool longitud :1;
  bool nombreConductor :1;
  bool nombreAseguradora :1;
  bool numPoliza :1;
  bool marca :1;
  bool modelo :1;
  bool color :1;
  bool placa :1;
  bool fechaHora :1;
  bool idConductor :1;
  bool idVehiculo :1;
  bool idIncidente :1;
} _Reporte__isset;

class Reporte : public virtual ::apache::thrift::TBase {
 public:

  Reporte(const Reporte&);
  Reporte& operator=(const Reporte&);
  Reporte() : idReporte(0), latitud(0), longitud(0), nombreConductor(), nombreAseguradora(), numPoliza(), marca(), modelo(), color(), placa(), fechaHora(), idConductor(0), idVehiculo(0), idIncidente(0) {
  }

  virtual ~Reporte() throw();
  int32_t idReporte;
  double latitud;
  double longitud;
  std::string nombreConductor;
  std::string nombreAseguradora;
  std::string numPoliza;
  std::string marca;
  std::string modelo;
  std::string color;
  std::string placa;
  std::string fechaHora;
  int32_t idConductor;
  int32_t idVehiculo;
  int32_t idIncidente;

  _Reporte__isset __isset;

  void __set_idReporte(const int32_t val);

  void __set_latitud(const double val);

  void __set_longitud(const double val);

  void __set_nombreConductor(const std::string& val);

  void __set_nombreAseguradora(const std::string& val);

  void __set_numPoliza(const std::string& val);

  void __set_marca(const std::string& val);

  void __set_modelo(const std::string& val);

  void __set_color(const std::string& val);

  void __set_placa(const std::string& val);

  void __set_fechaHora(const std::string& val);

  void __set_idConductor(const int32_t val);

  void __set_idVehiculo(const int32_t val);

  void __set_idIncidente(const int32_t val);

  bool operator == (const Reporte & rhs) const
  {
    if (!(idReporte == rhs.idReporte))
      return false;
    if (!(latitud == rhs.latitud))
      return false;
    if (!(longitud == rhs.longitud))
      return false;
    if (!(nombreConductor == rhs.nombreConductor))
      return false;
    if (!(nombreAseguradora == rhs.nombreAseguradora))
      return false;
    if (!(numPoliza == rhs.numPoliza))
      return false;
    if (!(marca == rhs.marca))
      return false;
    if (!(modelo == rhs.modelo))
      return false;
    if (!(color == rhs.color))
      return false;
    if (!(placa == rhs.placa))
      return false;
    if (!(fechaHora == rhs.fechaHora))
      return false;
    if (!(idConductor == rhs.idConductor))
      return false;
    if (!(idVehiculo == rhs.idVehiculo))
      return false;
    if (!(idIncidente == rhs.idIncidente))
      return false;
    return true;
  }
  bool operator != (const Reporte &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Reporte & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(Reporte &a, Reporte &b);

std::ostream& operator<<(std::ostream& out, const Reporte& obj);

typedef struct _Foto__isset {
  _Foto__isset() : idFoto(false), idReporte(false), foto(false), tiempoCreacion(false) {}
  bool idFoto :1;
  bool idReporte :1;
  bool foto :1;
  bool tiempoCreacion :1;
} _Foto__isset;

class Foto : public virtual ::apache::thrift::TBase {
 public:

  Foto(const Foto&);
  Foto& operator=(const Foto&);
  Foto() : idFoto(0), idReporte(0), foto(), tiempoCreacion() {
  }

  virtual ~Foto() throw();
  int32_t idFoto;
  int32_t idReporte;
  std::string foto;
  std::string tiempoCreacion;

  _Foto__isset __isset;

  void __set_idFoto(const int32_t val);

  void __set_idReporte(const int32_t val);

  void __set_foto(const std::string& val);

  void __set_tiempoCreacion(const std::string& val);

  bool operator == (const Foto & rhs) const
  {
    if (!(idFoto == rhs.idFoto))
      return false;
    if (!(idReporte == rhs.idReporte))
      return false;
    if (!(foto == rhs.foto))
      return false;
    if (!(tiempoCreacion == rhs.tiempoCreacion))
      return false;
    return true;
  }
  bool operator != (const Foto &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Foto & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(Foto &a, Foto &b);

std::ostream& operator<<(std::ostream& out, const Foto& obj);

typedef struct _Vehiculo__isset {
  _Vehiculo__isset() : idVehiculo(false), marca(false), modelo(false), anio(false), color(false), nombreAseguradora(false), numPoliza(false), placa(false) {}
  bool idVehiculo :1;
  bool marca :1;
  bool modelo :1;
  bool anio :1;
  bool color :1;
  bool nombreAseguradora :1;
  bool numPoliza :1;
  bool placa :1;
} _Vehiculo__isset;

class Vehiculo : public virtual ::apache::thrift::TBase {
 public:

  Vehiculo(const Vehiculo&);
  Vehiculo& operator=(const Vehiculo&);
  Vehiculo() : idVehiculo(0), marca(), modelo(), anio(0), color(), nombreAseguradora(), numPoliza(), placa() {
  }

  virtual ~Vehiculo() throw();
  int32_t idVehiculo;
  std::string marca;
  std::string modelo;
  int32_t anio;
  std::string color;
  std::string nombreAseguradora;
  std::string numPoliza;
  std::string placa;

  _Vehiculo__isset __isset;

  void __set_idVehiculo(const int32_t val);

  void __set_marca(const std::string& val);

  void __set_modelo(const std::string& val);

  void __set_anio(const int32_t val);

  void __set_color(const std::string& val);

  void __set_nombreAseguradora(const std::string& val);

  void __set_numPoliza(const std::string& val);

  void __set_placa(const std::string& val);

  bool operator == (const Vehiculo & rhs) const
  {
    if (!(idVehiculo == rhs.idVehiculo))
      return false;
    if (!(marca == rhs.marca))
      return false;
    if (!(modelo == rhs.modelo))
      return false;
    if (!(anio == rhs.anio))
      return false;
    if (!(color == rhs.color))
      return false;
    if (!(nombreAseguradora == rhs.nombreAseguradora))
      return false;
    if (!(numPoliza == rhs.numPoliza))
      return false;
    if (!(placa == rhs.placa))
      return false;
    return true;
  }
  bool operator != (const Vehiculo &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Vehiculo & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(Vehiculo &a, Vehiculo &b);

std::ostream& operator<<(std::ostream& out, const Vehiculo& obj);

typedef struct _VehiculoConductor__isset {
  _VehiculoConductor__isset() : idVehiculoConductor(false), idConductor(false), idVehiculo(false), propietario(false) {}
  bool idVehiculoConductor :1;
  bool idConductor :1;
  bool idVehiculo :1;
  bool propietario :1;
} _VehiculoConductor__isset;

class VehiculoConductor : public virtual ::apache::thrift::TBase {
 public:

  VehiculoConductor(const VehiculoConductor&);
  VehiculoConductor& operator=(const VehiculoConductor&);
  VehiculoConductor() : idVehiculoConductor(0), idConductor(0), idVehiculo(0), propietario() {
  }

  virtual ~VehiculoConductor() throw();
  int32_t idVehiculoConductor;
  int32_t idConductor;
  int32_t idVehiculo;
  std::string propietario;

  _VehiculoConductor__isset __isset;

  void __set_idVehiculoConductor(const int32_t val);

  void __set_idConductor(const int32_t val);

  void __set_idVehiculo(const int32_t val);

  void __set_propietario(const std::string& val);

  bool operator == (const VehiculoConductor & rhs) const
  {
    if (!(idVehiculoConductor == rhs.idVehiculoConductor))
      return false;
    if (!(idConductor == rhs.idConductor))
      return false;
    if (!(idVehiculo == rhs.idVehiculo))
      return false;
    if (!(propietario == rhs.propietario))
      return false;
    return true;
  }
  bool operator != (const VehiculoConductor &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const VehiculoConductor & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(VehiculoConductor &a, VehiculoConductor &b);

std::ostream& operator<<(std::ostream& out, const VehiculoConductor& obj);

} // namespace

#endif
