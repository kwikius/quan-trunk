#ifndef QUAN_UAV_BATTERY_HPP_INCLUDED
#define QUAN_UAV_BATTERY_HPP_INCLUDED

namespace quan{ namespace uav{

   struct battery{
      battery(std::string const & name,quan::charge_<float>::mA_h const & capacity)
      : m_name{name}, m_capacity{capacity}
      {}
      std::string const & get_name() const{return m_name;}
      quan::voltage_<float>::V get_voltage() const { return m_voltage;}
      quan::current::A get_current() const { return m_current;}
      quan::charge::mA_h get_charge_remaining() const{ return m_charge_remaining;}
      quan::charge::mA_h get_capacity()const{return m_capacity;}
      
      
      private:
      std::string                         m_name;
      quan::voltage_<float>::V            m_voltage;
      quan::current_<float>::A            m_current;
      quan::charge_<float>::mA_h          m_charge_remaining;
      quan::charge_<float>::mA_h const    m_capacity;
   };

}}


#endif // QUAN_UAV_BATTERY_HPP_INCLUDED
