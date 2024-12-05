#pragma once

class BaseService{
public:
    BaseService() = default;
    virtual ~BaseService() = default;
public:
    virtual void start() = 0;
    virtual void stop(){m_stop = false;}
protected:
    bool m_stop;
};