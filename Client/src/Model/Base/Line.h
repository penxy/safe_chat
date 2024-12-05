#ifndef __LINE_H__
#define __LINE_H__

#include <QFrame>

class Line : public QFrame{
public:
    enum class TypeLine{
        H,
        V
    };
    explicit Line(QWidget *parent = 0, TypeLine type = TypeLine::H);
};

#endif // __LINE_H__