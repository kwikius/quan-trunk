// Copyright Andrew Little 2006
// See QUAN_ROOT/quan_matters/index.html for documentation.

#include <quan/out/mass.hpp>
#include <quan/out/length.hpp>
#include <quan/out/time.hpp>
#include <quan/out/energy.hpp>
#include <memory>
#include <string>
#include <map>
#include <list>

// map quantities in various units
// to a target quantity via their output unit string
// use that to look up the conversion routine
template <typename TargetQuan>
class quantity_map{

    // abstract base class for converting 
    // to target fixed_quantity type
   
    struct abc_converter{
        virtual TargetQuan convert(double val)const=0;
        ~abc_converter(){} 
    };

    // implementation of the unit converter
    template <typename SourceQuan>
    struct converter : abc_converter{
        static_assert(std::is_convertible<SourceQuan,TargetQuan>::value,"only dimensionally equivalenet quantities are allowed");
        TargetQuan convert(double val)const
        {
            return SourceQuan(val);
        }
    };
public:
    typedef std::shared_ptr<abc_converter> quantity_ptr;
    typedef std::map<std::string,quantity_ptr> map_type;
    map_type m_map;

    template <typename SourceQuan>
    void add_unit()
    {
         static_assert(std::is_convertible<SourceQuan,TargetQuan>::value,"only dimensionally equivalenet quantities are allowed");
        if ( !this->find(units_str(SourceQuan())) ){
            quantity_ptr p(new converter<SourceQuan>);
            m_map [units_str(SourceQuan())]= p;
        }
    }

    bool find (std::string const & str)const
    {
        return m_map.find(str) != m_map.end();
    }

    template <typename List>
    void get_key_list( List & out_list)const
    {
        typedef typename map_type::const_iterator iter;
        for ( iter i = m_map.begin(); i != m_map.end(); ++i){
            out_list.push_back(i->first); 
        }
    }
    
};

int main()
{
    // fill the maps with units as required
    quantity_map<quan::mass::kg> mass_map;
    mass_map.add_unit<quan::mass::kg>();
    mass_map.add_unit<quan::mass::lb>();
   
    quantity_map<quan::time::s> time_map;
    time_map.add_unit<quan::time::s>();
    time_map.add_unit<quan::time::min>();
    time_map.add_unit<quan::time::h>();

    quantity_map<quan::length::m> length_map;
    length_map.add_unit<quan::length::m>();
    length_map.add_unit<quan::length::mi>();
    length_map.add_unit<quan::length::yd>();
    length_map.add_unit<quan::length::km>();
    
    // calculation input variables
    quan::mass::kg my_mass;
    quan::time::s my_time;
    quan::length::m my_distance;

    // user input variables
    std::string str;
    double val;
    
    while (1){
        std::cout << "How much do you weigh (specify lb or kg)? : ";
        std::cin >> val >> str;
        if ( ! mass_map.find(str)){
            std::cout << "Unfortunately " << str 
            << " units arent supported. Try another unit\n";
            continue;
        } else {
            my_mass = mass_map.m_map[str]->convert(val);
            break;
        }
    }
    while (1){
        std::cout << "How far did you walk (specify m, mi, yd, km)? : ";
        std::cin >> val >> str;
        if ( ! length_map.find(str)){
            std::cout << "Unfortunately " << str 
            << " units arent supported. Try another unit\n";
            continue;
        } else {
            my_distance = length_map.m_map[str]->convert(val);
            break;
        }
    }
    while (1){
        std::cout << "How long did you take? (specify min, s, h)? : ";
        std::cin >> val >> str;
        if ( ! time_map.find(str)){
            std::cout << "Unfortunately " << str 
            << " units arent supported. Try another unit\n";
            continue;
        } else {
            my_time = time_map.m_map[str]->convert(val);
            break;
        }
    }

    quan::energy::J my_energy = 0.5 * my_mass * quan::pow<2>(my_distance / my_time);
    std::cout << "Your kinetic energy was : " << my_energy << '\n';
}

/*
sample output:

How much do you weigh (specify lb or kg)? : 150 lb
How far did you walk (specify m, mi, yd, km)? : 20 mi
How long did you take? (specify min, s, h)? : 4 h
Your kinetic energy was : 169.965 J

*/
