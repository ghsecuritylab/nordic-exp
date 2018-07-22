#ifndef __CPP_HEADER_H__
#define __CPP_HEADER_H__

#include <stdint.h>

class LedWrapper
{
private: 
    uint32_t m_io_msk;
    bool m_active_high;

public:
    LedWrapper(uint32_t io_num, bool active_high);
    void On(void);
    void Off(void);
    void Toggle(void);
    void Write(bool on);
};


#endif

