#ifndef MENSAJE_H
#define MENSAJE_H

#include <string>
#include <iostream>

struct mensaje {
  int pid;
  int id;
  std::string texto;
};

inline std::ostream & operator<<(std::ostream & os, const mensaje & m) {
  return os << m.pid << " , " << m.id << " - " << m.texto;
}

#endif
