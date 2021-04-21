

#include <quan/fixed_quantity/fixed_quantity.hpp>
#include <quan/area.hpp>
#include <quan/length.hpp>

/**
* @brief In some formulas the dimensionless ratio between two quantities in different units needs to be expressed
* For exampe see https://www.sciencedirect.com/topics/engineering/standing-correlation.
* So the  quantity_ratio provides a way to define this ratio
* where scf is standard cubic foot and stb is standard barrel
*  quantity_ratio<scf,stb> K = 0.17810760667903525 //https://petroleumoffice.com/unitconverter
*/

template <typename Num, typename Den>
//requires std::is_arithmetic_v<decltype( Num{}/ Den{})>
struct quantity_ratio{
   using rep = std::common_type_t<float,typename Num::value_type,typename Den::value_type>;

   constexpr quantity_ratio() : m_value{0.}{}
   constexpr quantity_ratio( const rep & v)
   : m_value{v}{};

   constexpr operator rep() const  { return numeric_value();}

   /**
     * @brief convert the scaled value to a dimensionless number
    */
   constexpr rep numeric_value ()const
   {
      return (m_value * Num{1}) / Den{1};
   }
   constexpr quantity_ratio(quantity_ratio const &) = default;
   constexpr quantity_ratio & operator = (quantity_ratio const &) = default;
 private:
   friend std::ostream& operator << (std::ostream & os,quantity_ratio const & r)
   {
      return os <<  r.m_value << ' ' << units_str(Num{}) << '/' << units_str(Den{})  ;
   }

   rep m_value;
};

namespace quan{ namespace meta{

   template <typename Num, typename Den>
   struct is_numeric<quantity_ratio<Num,Den> > : quan::meta::true_{};
}}

#include <quan/out/volume.hpp>

int main()
{

    constexpr quantity_ratio<quan::volume::m3,quan::volume::m3> Rs = 0.45;

    std::cout << "Rs = " << Rs <<'\n'; 

    constexpr auto v = Rs.numeric_value();

    std::cout << "Rs numeric value = " << v << '\n'; 

}
