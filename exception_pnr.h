#ifndef EXCEPTION_PNR_H
#define EXCEPTION_PNR_H

#include <QString>

class Exception_PNR {

public:
   Exception_PNR(const QString& msg) : msg_(msg) {}
  ~Exception_PNR() {}

   QString getMessage() const {return(msg_);}
private:
   QString msg_;
};

#endif // EXCEPTION_PNR_H
