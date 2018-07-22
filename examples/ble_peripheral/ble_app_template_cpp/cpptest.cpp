#include "cpptest.h"
#include "nrf.h"

LedWrapper::LedWrapper(uint32_t io_num, bool active_high)
{
    m_active_high = active_high;
    m_io_msk = 1 << io_num;
    NRF_GPIO->DIRSET = m_io_msk;
}

void LedWrapper::On(void)
{
    if(m_active_high) NRF_GPIO->OUTSET = m_io_msk;
    else NRF_GPIO->OUTCLR = m_io_msk;
}

void LedWrapper::Off(void)
{
    if(m_active_high) NRF_GPIO->OUTCLR = m_io_msk;
    else NRF_GPIO->OUTSET = m_io_msk;    
}

void LedWrapper::Toggle(void)
{
    NRF_GPIO->OUT ^= m_io_msk;
}

void LedWrapper::Write(bool on)
{
    
}
