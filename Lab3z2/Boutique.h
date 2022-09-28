#pragma once
#include "IPayTax.h"
#include "IShopFunc.h"
#include "Time.h"
class  Boutique : public IShopFunc, public IPayTax
{
private:
    std::string m_title;
    int m_year;
    Time m_start;
    Time m_end;
    int  m_income;
public:
    // ŒÕ—“–” “Œ–
    Boutique();
    // ŒÕ—“–” “Œ– — œ¿–¿Ã≈“–¿Ã»
    Boutique(std::string _title, int _year, Time _start, Time _end, int _income);
    //¬»–“”¿À‹Õ€… ƒ≈—“–” “Œ–
    ~Boutique();
    virtual void setter()override;
    virtual void displayShop()override;
    virtual void seriallize(const std::string filename)override;
    virtual void deseriallize(const std::string filename)override;
    virtual void payTax() override;
};