#pragma once
#include <QSize>

namespace ui{
#ifndef sc
    #define sc static constexpr const
#endif
#ifndef QSize
    #define QSize ::QSize
#endif    
    
#ifdef QSize
    #undef QSize
#endif
#ifdef sc
    #undef sc
#endif // sc
}