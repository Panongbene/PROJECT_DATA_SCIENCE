/*************************************************************************************************
*Ce document est confidentiel. C'est la propriété de la société Gaindé. Il est interdit d'ouvrir
*, de copier, de modifier ou de faire quelque chose d'autre dans ce document si vous n'en avez pas 
*l'autorisation. Vous risquez des pursuits judiciaries.
**************************************************************************************************
*This document is confidential. It is the property of the company Gaindé. You may not open, copy, 
*modify, or do anything else in this document if you do not have permission to do so. You risk 
*judicaires prosecution.
*************************************************************************************************/
/*************************************************************************************************
*les benefices doivent etre de 10fcfa sur le km pour les courtes distance 10 a 20km avec un minimun de
*100fcfa de benefices par courses, de 5fcfa sur les distance moyens de 20 a 100km avec un minimun de
*200fcfa de benefice, de 2fcfa sur les longues distances de +100km avec un minimun de 500fcfa de benefice
*
*
*Les differents fichiers utiliser seront sous forme de fichier csv avec les champs separes par des ;
*Pour optimiser l acces au donnes des prix on pensera mettre en cache les prix des trajets qui seront recharges
*pour une duree donnee en fonction du fichier
**************************************************************************************************/
#include "Price.hpp"
//initialization of the variables
const char* namefile_PRICE_SECTOR="PRICE/PRICE_SECTOR.csv";
const char* namefile_PRICE_CIRCULATION_CATEGORY="PRICE/PRICE_CILCULATION_CATEGORY.csv";
const char* namefile_BASIC_PRICE="PRICE/BASIC_PRICE.csv";
const char* namefile_BENEFICES_NIANI="PRICE/BENEFICES_NIANI.csv";
const char* namefile_CORRESPONDANCE="PRICE/CORRESPONDANCE.csv";
const char* namefile_VEHICULE_CIRCULATION="PRICE/VEHICULE_CIRCULATION.csv";
const char* namefile_CIRCULATION="CIRCULATION.csv";
const char* namefile_UPDATE_TIME="UPDATE_TIME.csv";

//const unsigned long periode_seconde=600;


std::vector<std::vector<std::string> >* Price::price_sector=new std::vector<std::vector<std::string> >;
std::vector<std::vector<std::string> >* Price::price_circulation_category=new std::vector<std::vector<std::string> >;
std::vector<std::vector<std::string> >* Price::basic_price=new std::vector<std::vector<std::string> >;
std::vector<std::vector<std::string> >* Price::benefice_niani=new std::vector<std::vector<std::string> >;
std::vector<std::vector<std::string> >* Price::correspondance=new std::vector<std::vector<std::string> >;
std::vector<std::vector<std::string> >* Price::vehicule_circulation=new std::vector<std::vector<std::string> >;
std::vector<std::vector<std::string> >* Price::circulation=new std::vector<std::vector<std::string> >;
unsigned long* Price::periode_seconde=new unsigned long;
/*************************************************************************************************/
unsigned long Price::getperiode_seconde()
	  {
	   return *Price::periode_seconde;
	  }
/*************************************************************************************************/
std::vector<std::vector<std::string> > Price::getprice_sector()
	  {
		return *Price::price_sector;
	  }
/*************************************************************************************************/
std::vector<std::vector<std::string> > Price::getprice_circulation_category()
	  {
       return *Price::price_circulation_category;
	  }
/*************************************************************************************************/
std::vector<std::vector<std::string> > Price::getbasic_price()
	 {
	  return *Price::basic_price;
	 }
/*************************************************************************************************/
std::vector<std::vector<std::string> > Price::getbenefice_niani()
	 {
	  return *Price::benefice_niani;
	 }
/*************************************************************************************************/
std::vector<std::vector<std::string> > Price::getcorrespondance()
	 {
	  return *Price::correspondance;
	 }
/*************************************************************************************************/
std::vector<std::vector<std::string> > Price::getvehicule_circulation()
	 {
	  return *Price::vehicule_circulation;
	 }
/*************************************************************************************************/
std::vector<std::vector<std::string> > Price::getcirculation()
	 {
	  return *Price::circulation;	
	 }
/*************************************************************************************************/
void Price::load_periode_seconde(unsigned long* periode_seconde, const char* namefile)
	 {
	  //variable
	  std::string ligne;		   
      std::ifstream fichier(namefile,std::ios::in);
	  
	  //Open file
       if(fichier)
            {
             if(std::getline(fichier,ligne)==NULL)//end of file
				{
				  std::cout<<"fichier incorrecte"<<std::endl;
				  return;
		   		}
		   	  
		   	 *periode_seconde=Price::convert_string_int(ligne);
			}
		else
            {
             std::cerr<<"ERROR OPEN FILE BENEFICES_NIANI"<<std::endl;	
             return;
            }
		   
		//close file  
        fichier.close();
            
	 	return;
	 }
/*************************************************************************************************/
void Price::load_price_sector( std::vector<std::vector<std::string> >* price_sector,const char* namefile)
	 {
	 //variable
	  int number_line=0;
	  std::string ligne;		   
      std::ifstream fichier(namefile,std::ios::in);
	  
	  //Open file
       if(fichier)
            {
             while(true)
                {
                 number_line++;
                 if(std::getline(fichier,ligne)==NULL)//end of file
					 break;
					 
	     		 std::vector<std::string> tamp;
		        
				 //find the first and second position of ;
			     int first=ligne.find_first_of(';',0);
			  	 int second=ligne.find_first_of(';',first+1);
			  	   
                 //test if the line is correcte
			  	 if(first==-1 || second==-1)
 	 	 	        {
					 std::cout<<"Line number ="<<number_line<<" : "<<ligne<<"  is bad"<<std::endl;
					 continue;	
					}
					  
                  //extract the value of sector and type vehicle in this line
				   std::string secteur=ligne.substr(0,first);
				   std::string vehicule=ligne.substr(first+1,second-first);
				   std::string prix=ligne.substr(second+1);
				   
				  //insert data to the tamp
				   tamp.push_back(secteur);
				   tamp.push_back(vehicule);
				   tamp.push_back(prix);
				   
				  //insert the ligne in the conteneur
				   price_sector->push_back(tamp);
	              }
              }
		    else
              {
               std::cerr<<"ERROR OPEN FILE PRICE_SECTOR"<<std::endl;	
               return;
              }
		   
		   //close file  
            fichier.close();
	 }
/*************************************************************************************************/
void Price::load_price_circulation_category( std::vector<std::vector<std::string> >* price_circulation_category,const char* namefile)
	 {
	  //variable
	  int number_line=0;
	  std::string ligne;		   
      std::ifstream fichier(namefile,std::ios::in);
	  
	  //Open file
       if(fichier)
            {
             while(true)
                {
                 number_line++;
                 if(std::getline(fichier,ligne)==NULL)//end of file
					 break;
					 
	     		 std::vector<std::string> tamp;
		        
				 //find the first and second position of ;
			     int first=ligne.find_first_of(';',0);
			  	   
                 //test if the line is correcte
			  	 if(first==-1)
 	 	 	        {
					 std::cout<<"Line number ="<<number_line<<" : "<<ligne<<"  is bad"<<std::endl;
					 continue;	
					}
					  
                  //extract the value of sector and type vehicle in this line
				   std::string categorie=ligne.substr(0,first);
				   std::string prix=ligne.substr(first+1);
				   
				  //insert data to the tamp
				   tamp.push_back(categorie);
				   tamp.push_back(prix);
				   
				  //insert the ligne in the conteneur
				   price_circulation_category->push_back(tamp);
	              }
              }
		    else
              {
               std::cerr<<"ERROR OPEN FILE PRICE_CILCULATION_CATEGORY"<<std::endl;	
               return;
              }
		   
		   //close file  
            fichier.close();
        
	  return;
     }
/*************************************************************************************************/
void Price::load_basic_price(std::vector<std::vector<std::string> > *basic_price,const char* namefile)
	 {
	  //variable
	  int number_line=0;
	  std::string ligne;		   
      std::ifstream fichier(namefile,std::ios::in);
	  
	  //Open file
       if(fichier)
            {
             while(true)
                {
                 number_line++;
                 if(std::getline(fichier,ligne)==NULL)//end of file
					 break;
					 
	     		 std::vector<std::string> tamp;
		        
				 //find the first and second position of ;
			     int first=ligne.find_first_of(';',0);
			  	   
                 //test if the line is correcte
			  	 if(first==-1)
 	 	 	        {
					 std::cout<<"Line number ="<<number_line<<" : "<<ligne<<"  is bad"<<std::endl;
					 continue;	
					}
					  
                  //extract the value of sector and type vehicle in this line
				   std::string categorie=ligne.substr(0,first);
				   std::string prix=ligne.substr(first+1);
				   
				  //insert data to the tamp
				   tamp.push_back(categorie);
				   tamp.push_back(prix);
				   
				  //insert the ligne in the conteneur
				   basic_price->push_back(tamp);
	              }
              }
		    else
              {
               std::cerr<<"ERROR OPEN FILE BASIC_PRICE"<<std::endl;	
               return;
              }
		   
		   //close file  
            fichier.close();
            
	 	return;
	 }
/*************************************************************************************************/
void Price::load_benefice_niani(std::vector<std::vector<std::string> > *benefice_niani,const char* namefile)
	 {
	  //variable
	  int number_line=0;
	  std::string ligne;		   
      std::ifstream fichier(namefile,std::ios::in);
	  
	  //Open file
       if(fichier)
            {
             while(true)
                {
                 number_line++;
                 if(std::getline(fichier,ligne)==NULL)//end of file
					 break;
					 
	     		 std::vector<std::string> tamp;
		        
				 //find the first and second position of ;
			     int first=ligne.find_first_of(';',0);
			  	   
                 //test if the line is correcte
			  	 if(first==-1)
 	 	 	        {
					 std::cout<<"Line number ="<<number_line<<" : "<<ligne<<"  is bad"<<std::endl;
					 continue;	
					}
					  
                  //extract the value of sector and type vehicle in this line
				   std::string categorie=ligne.substr(0,first);
				   std::string prix=ligne.substr(first+1);
				   
				  //insert data to the tamp
				   tamp.push_back(categorie);
				   tamp.push_back(prix);
				   
				  //insert the ligne in the conteneur
				   benefice_niani->push_back(tamp);
	              }
              }
		    else
              {
               std::cerr<<"ERROR OPEN FILE BENEFICES_NIANI"<<std::endl;	
               return;
              }
		   
		   //close file  
            fichier.close();
            
	 	return;
 	 }
/*************************************************************************************************/
void Price::load_correspondance( std::vector<std::vector<std::string> >* correspondance,const char* namefile)
	 {
	 //variable
	  int number_line=0;
	  std::string ligne;		   
      std::ifstream fichier(namefile,std::ios::in);
	  
	  //Open file
       if(fichier)
            {
             while(true)
                {
                 number_line++;
                 if(std::getline(fichier,ligne)==NULL)//end of file
					 break;
					 
	     		 std::vector<std::string> tamp;
		        
				 //find the first and second position of ;
			     int first=ligne.find_first_of(';',0);
			  	 int second=ligne.find_first_of(';',first+1);
			  	 int third=ligne.find_first_of(';',second+1);
			  	 int fourth=ligne.find_first_of(';',third+1);
			  	 int fifth=ligne.find_first_of(';',fourth+1);
                 //test if the line is correcte
			  	 if(first==-1||second==-1||third==-1||fourth==-1||fifth==-1)
 	 	 	        {
					 std::cout<<"Line number ="<<number_line<<" : "<<ligne<<"  is bad"<<std::endl;
					 continue;	
					}
					  
                  //extract the value of sector and type vehicle in this line
				   std::string categorie=ligne.substr(0,first);
				   std::string nom_secteur=ligne.substr(first,second-first);
				   std::string coordonnee1=ligne.substr(second,third-second);
				   std::string coordonnee2=ligne.substr(third,fourth-third);
				   std::string coordonnee3=ligne.substr(fourth,fifth-fourth);
				   std::string coordonnee4=ligne.substr(fifth);
				  
				  //insert data to the tamp
				   tamp.push_back(categorie);
				   tamp.push_back(nom_secteur);
				   tamp.push_back(coordonnee1);
				   tamp.push_back(coordonnee2);
				   tamp.push_back(coordonnee3);
				   tamp.push_back(coordonnee4);
				   
				  //insert the ligne in the conteneur
				   correspondance->push_back(tamp);
	              }
              }
		    else
              {
               std::cerr<<"ERROR OPEN FILE CORRESPONDANCE"<<std::endl;	
               return;
              }
		   
		   //close file  
            fichier.close();
            
	 	return;
	 }
/*************************************************************************************************/
void Price::load_vehicule_circulation(std::vector<std::vector<std::string> >* vehicule_circulation,const char* namefile)
	 {
	  //variable
	  int number_line=0;
	  std::string ligne;		   
      std::ifstream fichier(namefile,std::ios::in);
	  
	  //Open file
       if(fichier)
            {
             while(true)
                {
                 number_line++;
                 if(std::getline(fichier,ligne)==NULL)//end of file
					 break;
					 
	     		 std::vector<std::string> tamp;
		        
				 //find the first and second position of ;
			     int first=ligne.find_first_of(';',0);
			  	   
                 //test if the line is correcte
			  	 if(first==-1)
 	 	 	        {
					 std::cout<<"Line number ="<<number_line<<" : "<<ligne<<"  is bad"<<std::endl;
					 continue;	
					}
					  
                  //extract the value of sector and type vehicle in this line
				   std::string categorie=ligne.substr(0,first);
				   std::string nom_vehicule=ligne.substr(first+1);
				   
				  //insert data to the tamp
				   tamp.push_back(categorie);
				   tamp.push_back(nom_vehicule);
				   
				  //insert the ligne in the conteneur
				   vehicule_circulation->push_back(tamp);
	              }
              }
		    else
              {
               std::cerr<<"ERROR OPEN FILE VEHICULE_CIRCULATION"<<std::endl;	
               return;
              }
		   
		   //close file  
            fichier.close();
            
	 	return;
	 }
/*************************************************************************************************/
void Price::load_circulation( std::vector<std::vector<std::string> >* circulation,const char* namefile)
	 {
	  //variable
	  int number_line=0;
	  std::string ligne;		   
      std::ifstream fichier(namefile,std::ios::in);
	  
	  //Open file
       if(fichier)
            {
             while(true)
                {
                 number_line++;
                 if(std::getline(fichier,ligne)==NULL)//end of file
					 break;
					 
	     		 std::vector<std::string> tamp;
		        
				 //find the first and second position of ;
			     int first=ligne.find_first_of(';',0);
			  	   
                 //test if the line is correcte
			  	 if(first==-1)
 	 	 	        {
					 std::cout<<"Line number ="<<number_line<<" : "<<ligne<<"  is bad"<<std::endl;
					 continue;	
					}
					  
                  //extract the value of sector and type vehicle in this line
				   std::string categorie=ligne.substr(0,first);
				   std::string nom_circulation=ligne.substr(first+1);
				   
				  //insert data to the tamp
				   tamp.push_back(categorie);
				   tamp.push_back(nom_circulation);
				   
				  //insert the ligne in the conteneur
				   circulation->push_back(tamp);
	              }
              }
		    else
              {
               std::cerr<<"ERROR OPEN FILE CIRCULATION"<<std::endl;	
               return;
              }
		   
		   //close file  
            fichier.close();
            
	 	return;
	 }
/*************************************************************************************************/
void Price::load_data_per_time(unsigned long periode_seconde1, unsigned long* periode_seconde, std::vector<std::vector<std::string> >* price_sector, std::vector<std::vector<std::string> >* price_circulation_category, std::vector<std::vector<std::string> > *basic_price, std::vector<std::vector<std::string> > *benefice_niani, std::vector<std::vector<std::string> >* correspondance, std::vector<std::vector<std::string> >* vehicule_circulation, std::vector<std::vector<std::string> >* circulation)
	 {
	  while(true)
		{
		 Price::load_periode_seconde(periode_seconde,namefile_UPDATE_TIME);
		 Price::load_price_sector(price_sector,namefile_PRICE_SECTOR);
	  	 Price::load_price_circulation_category(price_circulation_category,namefile_PRICE_CIRCULATION_CATEGORY);
	  	 Price::load_basic_price(basic_price,namefile_BASIC_PRICE);
	  	 Price::load_benefice_niani(benefice_niani,namefile_BENEFICES_NIANI);
	  	 Price::load_correspondance(correspondance,namefile_CORRESPONDANCE);
	  	 Price::load_vehicule_circulation(vehicule_circulation,namefile_VEHICULE_CIRCULATION);
	  	 Price::load_circulation(circulation,namefile_CIRCULATION);
		
		 int k=0;
		 periode_seconde1=*periode_seconde;
		 std::cout<<" Remaining time before loading data(minute) : ";
		 while(k<=periode_seconde1)
		    {
		     k++;
		 	 std::cout<<periode_seconde1-k<<";  "<<std::endl;//for read the time staying before update
		 	 std::this_thread::sleep_for (std::chrono::seconds(10)); //1second of pause
			}
		 std::cout<<"\n";
		}	  
	 	
	 }
/*************************************************************************************************/
//this function take a integer string and to convert this at numerical integer
int Price::convert_string_int(std::string ss)
		{
     	 std::stringstream geek(ss);
     	 int x=0.0;
     	 geek>>x;
     	 return x;
		}
/*************************************************************************************************/
//this function take a double string and to convert this at numerical double
double Price::convert_string_double(std::string ss)
		{
	     std::stringstream geek(ss);
     	 double x=0.0;
     	 geek>>x;
     	 return x;
		}
/*************************************************************************************************/
//this function take a numerical integer and to convert this at an string
std::string Price::convert_int_string(int value)
		{
		 std::stringstream ss;
		 ss << value;
         return ss.str();
		}
/*************************************************************************************************/
//this function take a numerical integer and to convert this at an string
std::string Price::convert_double_string(double value)
		{
     	 std::stringstream ss;
		 ss << value;
         return ss.str();
		}
/*************************************************************************************************/
void Price::free_price_sector()
		{
		 delete price_sector;	
		 return;
		}
/*************************************************************************************************/
void Price::free_price_circulation_category()
		{
		 delete price_circulation_category;
		 return;
		}
/*************************************************************************************************/
void Price::free_basic_price()
		{
		 delete basic_price;
		 return;
		}
/*************************************************************************************************/
void Price::free_benefice_niani()
		{
		 delete benefice_niani;
		 return;
		}
/*************************************************************************************************/
void Price::free_correspondance( )
		{
		 delete correspondance;
		 return;
		}
/*************************************************************************************************/
void Price::free_vehicule_circulation()
		{
		 delete vehicule_circulation;
		 return;
		}
/*************************************************************************************************/
void Price::free_circulation()
		{
		 delete circulation;	
		 return;
		}
/*************************************************************************************************/
double Price::getprice_sector(int sector,int type_vehicle)
		{
		 double prix=-1.0;
		 
		 for(size_t k=0;k<Price::price_sector->size();k++)
		 	{
		 	 if(Price::convert_string_int((*Price::price_sector)[k][0])==sector,Price::convert_string_int((*Price::price_sector)[k][1])==type_vehicle)
		 	    {
				 prix=Price::convert_string_double((*Price::price_sector)[k][2]);
			     break;
				}
			}
		 if(prix<0)
		 	{
		 	 std::cout<<"Sector : "<<sector<<"  Type_Vehicle : "<<type_vehicle<<" Not found";
			 prix=0.0;
		    }
		    
		 return prix;
		}
/*************************************************************************************************/
double Price::getprice_circulation_category(int circulation_category)
		{
		 double prix=-1.0;
		 
		 for(size_t k=0;k<Price::price_circulation_category->size();k++)
		 	{
		 	 if(Price::convert_string_int((*Price::price_circulation_category)[k][0])==circulation_category)
		 	    {
				 prix=Price::convert_string_double((*Price::price_circulation_category)[k][1]);
			     break;
				}
			}
		 if(prix<0)
		 	{
		 	 std::cout<<"Circulation_Category : "<<circulation_category<<" Not found";
			 prix=0.0;
		    }
		    
		 return prix;
		}
/*************************************************************************************************/
double Price::getbasic_price(int type_vehicle)
		{
		 double prix=-1.0;
		 
		 for(size_t k=0;k<Price::basic_price->size();k++)
		 	{
		 	 if(Price::convert_string_int((*Price::basic_price)[k][0])==type_vehicle)
		 	    {
				 prix=Price::convert_string_double((*Price::basic_price)[k][1]);
			     break;
				}
			}
		 if(prix<0)
		 	{
		 	 std::cout<<"Vehicule Type : "<<type_vehicle<<" Not found";
			 prix=0.0;
		    }
		    
		 return prix;
		}
/*************************************************************************************************/
double Price::getbenefices_niani(int distance_metter)
		{
		 double prix=-1.0;
		 
		 for(size_t k=0;k<Price::benefice_niani->size();k++)
		 	{
		 	 if(Price::convert_string_int((*Price::benefice_niani)[k][0])==distance_metter)
		 	    {
				 prix=Price::convert_string_double((*Price::benefice_niani)[k][1]);
			     break;
				}
			}
		 if(prix<0)
		 	{
		 	 std::cout<<"Distance_metter : "<<distance_metter<<" Not found";
			 prix=0.0;
		    }
		    
		 return prix;
		}
/*************************************************************************************************/
static std::vector<std::string> get_sector_correspondance(int sector)
		{
		 std::vector<std::string> tamp;
		 
		 for(size_t k=0;k<Price::correspondance->size();k++)
		 	{
		 	 if(Price::convert_string_int((*Price::correspondance)[k][0])==sector)
		 	    {
				 tamp.push_back((*Price::correspondance)[k][0]);
				 tamp.push_back((*Price::correspondance)[k][1]);
				 tamp.push_back((*Price::correspondance)[k][2]);
				 tamp.push_back((*Price::correspondance)[k][3]);
				 tamp.push_back((*Price::correspondance)[k][4]);
				 tamp.push_back((*Price::correspondance)[k][5]);
				 
			     break;
				}
			}
			
		 if(tamp.size()==0)
		 	{
		 	 tamp.push_back("ERROR");
		    }
		    
		 return tamp;
		}
/*************************************************************************************************/
static std::vector<std::string> get_category_vehicule_circulation(int category)
		{
		 std::vector<std::string> tamp;
		 
		 for(size_t k=0;k<Price::vehicule_circulation->size();k++)
		 	{
		 	 if(Price::convert_string_int((*Price::vehicule_circulation)[k][0])==category)
		 	    {
				 tamp.push_back((*Price::vehicule_circulation)[k][0]);
				 tamp.push_back((*Price::vehicule_circulation)[k][1]);
			     break;
				}
			}
			
		 if(tamp.size()==0)
		 	{
		 	 tamp.push_back("ERROR");
		    }
		    
		 return tamp;
		}
/*************************************************************************************************/
static std::vector<std::string> get_category_circulation(int category)
		{
         std::vector<std::string> tamp;
		 
		 for(size_t k=0;k<Price::circulation->size();k++)
		 	{
		 	 if(Price::convert_string_int((*Price::circulation)[k][0])==category)
		 	    {
				 tamp.push_back((*Price::circulation)[k][0]);
				 tamp.push_back((*Price::circulation)[k][1]);
			     break;
				}
			}
			
		 if(tamp.size()==0)
		 	{
		 	 tamp.push_back("ERROR");
		    }
		    
		 return tamp;
		}
/*************************************************************************************************/

double Price::getprice(int distance_metter,int sector,int type_vehicle,int circulation_category)
		{
		 double prix_secteur=Price::getprice_sector(sector,type_vehicle);
		 double benefice_niani=Price::getbenefices_niani(distance_metter);
		 double prix_circulation=Price::getprice_circulation_category(circulation_category);
		 
		 //test if value is correct else, getprice return -1.0
		 if(prix_secteur<0||benefice_niani<0||prix_circulation<0)
		 	{
		 	 std::cout<<"ERROR GETPRICE"<<std::endl;
		 	 return -1.0;
			}
		 
		 double price=distance_metter*(prix_secteur+benefice_niani)+prix_circulation;
		 double basik_price=Price::getbenefices_niani(type_vehicle);
		  
		 if(basik_price>price)
		  	price=basik_price;
		
	 	 return price;
		}
/*************************************************************************************************/
/*************************************************************************************************/
/*************************************************************************************************/
/*************************************************************************************************/
/*************************************************************************************************/
/*************************************************************************************************/
