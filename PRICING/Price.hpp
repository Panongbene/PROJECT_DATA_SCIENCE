/*************************************************************************************************
*Ce document est confidentiel. C'est la propriété de la société Gaindé. Il est interdit d'ouvrir
*, de copier, de modifier ou de faire quelque chose d'autre dans ce document si vous n'en avez pas 
*l'autorisation. Vous risquez des pursuits judiciaries.
**************************************************************************************************
*This document is confidential. It is the property of the company Gaindé. You may not open, copy, 
*modify, or do anything else in this document if you do not have permission to do so. You risk 
*judicaires prosecution.
*************************************************************************************************/
#ifndef PRICE_HPP
#define PRICE_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <thread>         // std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds

class Price
  {
/*******************************************************************************************************************************/
  	public:
  		   /********************************************************************************/
		   /*
		   *this function return the data of price sector
		   */
  		   static unsigned long getperiode_seconde();
	  	   /********************************************************************************/
		   /*
		   *this function return the data of price sector
		   */
		   static std::vector<std::vector<std::string> > getprice_sector();
		   /********************************************************************************/
		   /*
		   *this function return the data of circulation category
		   */
		   static std::vector<std::vector<std::string> > getprice_circulation_category();
		   /********************************************************************************/
		   /*
		   *this function return the data of basic price
		   */
		   static std::vector<std::vector<std::string> > getbasic_price();
		   /********************************************************************************/
		   /*
		   *this function return the data of benefice Niani
	       */
		   static std::vector<std::vector<std::string> > getbenefice_niani();
		   /********************************************************************************/
		   /*
		   *this function return the data of correspondance
		   */
		   static std::vector<std::vector<std::string> > getcorrespondance();
		   /********************************************************************************/
		   /*
		   *this function return the datar of circulation
		   */
		   static std::vector<std::vector<std::string> > getvehicule_circulation();
		   /********************************************************************************/
		   /*
		   *this function return the pointeur of circulation
		   */
		   static std::vector<std::vector<std::string> > getcirculation();
		   /********************************************************************************/
		   /*
		   *this function allow the load the data of price sector
		   */
		   static void load_periode_seconde(unsigned long* periode_seconde, const char* namefile);
		   /********************************************************************************/
		   /*
		   *this function allow the load the data of price sector
		   */
		   static void load_price_sector( std::vector<std::vector<std::string> >* price_sector,const char* namefile);
		   /********************************************************************************/
		   /*
		   *this function allow the load the data of circulation category
		   */
		   static void load_price_circulation_category( std::vector<std::vector<std::string> >* price_circulation_category,const char* namefile);
		   /********************************************************************************/
		   /*
		   *this function allow the load the data of basic price
		   */
		   static void load_basic_price(std::vector<std::vector<std::string> > *basic_price,const char* namefile);
		   /********************************************************************************/
		   /*
		   *this function return the pointeur of benefice Niani
	       */
		   static void load_benefice_niani(std::vector<std::vector<std::string> > *benefice_niani,const char* namefile);
		   /********************************************************************************/
		   /*
		   *this function return the pointeur of correspondance
		   */
		   static void load_correspondance( std::vector<std::vector<std::string> >* correspondance,const char* namefile);
		   /********************************************************************************/
		   /*
		   *this function return the pointeur of vehicule circulation
		   */
		   static void load_vehicule_circulation(std::vector<std::vector<std::string> >* vehicule_circulation,const char* namefile);
		   /********************************************************************************/
		   /*
		   *this function return the pointeur of  circulation
		   */
		   static void load_circulation( std::vector<std::vector<std::string> >* circulation,const char* namefile);
		   /********************************************************************************/
		   /*
		   *This function load the data per periode
		   */
		   static void load_data_per_time(unsigned long periode_seconde1, unsigned long* periode_seconde, std::vector<std::vector<std::string> >* price_sector, std::vector<std::vector<std::string> >* price_circulation_category, std::vector<std::vector<std::string> > *basic_price, std::vector<std::vector<std::string> > *benefice_niani, std::vector<std::vector<std::string> >* correspondance, std::vector<std::vector<std::string> >* vehicule_circulation, std::vector<std::vector<std::string> >* circulation);

		   /********************************************************************************/
		   /*
		   *This function convert a string in integer
		   */
		   static int convert_string_int(std::string ss);
		   /********************************************************************************/
		   /*
		   *This function convert a string in double
		   */
		   static double convert_string_double(std::string ss);
		   /********************************************************************************/
		   /*
		   *This function convert the integer in string
		   */
           static std::string convert_int_string(int value);
           /********************************************************************************/
		   /*
		   *This function convert the reel in double
		   */
           static std::string convert_double_string(double value);
		   /********************************************************************************/
		   /*
		   *this function release the data of price sector
		   */
		   static void free_price_sector();
		   /********************************************************************************/
		   /*
		   *this function release the data of circulation category
		   */
		   static void free_price_circulation_category();
		   /********************************************************************************/
		   /*
		   *this function release the data of basic price
		   */
		   static void free_basic_price();
		   /********************************************************************************/
		   /*
		   *this function release the data of benefice Niani
	       */
		   static void free_benefice_niani();
		   /********************************************************************************/
		   /*
		   *this function release the data of correspondance
		   */
		   static void free_correspondance( );
		   /********************************************************************************/
		   /*
		   *this function release the data of circulation
		   */
		   static void free_vehicule_circulation();
		   /********************************************************************************/
		   /*
		   *this function release the data of circulation
		   */
		   static void free_circulation();
	  	   /********************************************************************************/
		   /*
		   *This is the default constructor
		   */
		   
		   Price();
	   	   /********************************************************************************/
		   /*
		   *This is the default constructor
		   */
		   ~Price();
		   /********************************************************************************/
		   /*
		   *This function determinate the price of 1 meter of travel depending on the sector 
		   *and the type of vehicle
		   */
		   static double getprice_sector(int sector,int type_vehicle);
		   /********************************************************************************/
		   /*
		   *This function determinate the price that we add because the circulation or different
		   *evenement
		   */
		   static double getprice_circulation_category(int circulation_category);
		   /********************************************************************************/
		   /*
		   *This function determinate the basic price in function of vehicle type
		   */
		   static double getbasic_price(int type_vehicle);
		   /********************************************************************************/
		   /*
			*This calculate the benefice of niani in function the distance
		   */
		   static double getbenefices_niani(int distance_metter);
		   /********************************************************************************/
		   /*
		   *this function return the correspondance of the sector
		   */
		   static std::vector<std::string> get_sector_correspondance(int sector);
		   /********************************************************************************/
		   /*
		   *this function return the name of vehicule of the category
		   */
		   static std::vector<std::string> get_category_vehicule_circulation(int category);
		   /********************************************************************************/
		   /*
		   *this function return the name of circulation of the category
		   */
		   static std::vector<std::string> get_category_circulation(int category);
		   /********************************************************************************/
		   /*
		   *This function determinate the price of a trajet
		   */
		   static double getprice(int distance_metter,int sector,int type_vehicle,int circulation_category=0);
		   /********************************************************************************/
		   /*
		   *the array of price sector
		   */
		   static std::vector<std::vector<std::string> > *price_sector;
		   /********************************************************************************/
		   /*
		   *The array of price circulation category
		   */
		   static std::vector<std::vector<std::string> > *price_circulation_category;
		   /********************************************************************************/
		   /*
		   *The array of basic price
		   */
		   static std::vector<std::vector<std::string> > *basic_price;
		   /********************************************************************************/
		   /*
		   *The array of benefice Niani
	       */
		   static std::vector<std::vector<std::string> > *benefice_niani;
		   /********************************************************************************/
		   /*
		   *The array of correspondance
		   */
		   static std::vector<std::vector<std::string> > *correspondance;
		   /********************************************************************************/
		   /*
		   *The array of vehicule circulation
		   */
		   static std::vector<std::vector<std::string> > *vehicule_circulation;
		   /********************************************************************************/
		   /*
		   *The array of circulation
		   */
		   static std::vector<std::vector<std::string> > *circulation;
		   /********************************************************************************/
		   /*
		   *This is the time to update the data
		   */
		   static unsigned long* periode_seconde;
/*******************************************************************************************************************************/
	};
/********************************************************************************/
#endif //PRICE_HPP
