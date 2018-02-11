/*
 * Name        : temperature.h
 * Author      : Michael Farrar
 * Description : Class Header File
 */

// ADD HEADER GUARD HERE


#include <string>
#include <sstream>
using std::string;
using std::stringstream;

/*
 * Class Temperature.
 * A class that converts temperatures. It will always internally store the value
 * in double kelvin.
 */
class Temperature {
 protected:
  double kelvin_;
 public:
  /*
   * Constructor #1.
   * Sets double kelvin_ to 0
   *
   * Constructor #1.
   * Sets double kelvin_ to 0
   */
   Temperature() {
    double kelvin_ = 0.0
   
  }

  /*
   * Constructor #2.
   * Sets double kelvin_ to the supplied value
   * @param double kelvin - The value to set the internal double kelvin to
   */
   Temperature(double kelvin){
   : kelvin_(kelvin);
  }

  /*
   * Constructor #3.
   * Converts the supplied temperature to double kelvin and internally stores it.
   * The temperature's unit will be provided in the second argument.
   * If the second argument is not value (i.e. not 'F' or 'C') assume the
   * temperature is in double kelvin
   * @param double temp - The value to set the internal double kelvin to once
   *                    - converted.
   * @param char unit - The type of unit temp is. Will be either 'F' or 'C',
   *                    case-insensitive
   */
  Temperature(double temp, char unit){
   double kelvin_ = temp;
   char unit_ = unit;
  }

  /*
   * The temperature will come in as double kelvin and this function will set the
   * internal temp to this value
   * @param double kelvin - The value to set the internal double kelvin to.
   */
   void SetTempFromKelvin(double kelvin){
   kelvin_ = kelvin;
  }


  /*
   * The temperature will come in as Celsius and this function will set the
   * internal temp to this value, once converted to double kelvin
   * Formula: k = c + 273.15
   * @param double celsius - The value (in celsius) to set the internal double kelvin
   *                       - to.
   */
   void SetTempFromCelsius(double celsius)
  {
   double kelvin_ = celsius + 273.15;
  }


  /*
   * The temperature will come in as Fahrenheit and this function will set the
   * internal temp to this value, once converted to double kelvin
   * Formula: k = (5.0 * (f - 32) / 9) + 273.15
   * @param double fahrenheit - The value (in fahrenheit) to set the internal
   *                          - double kelvin to.
   */
  void SetTempFromFahrenheit(double fahrenheit){
   double kelvin_ = (5.0 * (fahrenheit - 32) / 9) + 273.15;
  }

  /*
   * Gets the internal temperature in Kelvin.
   * @return double - The temperature in Kelvin
   */
  double GetTempAsKelvin() const{
   return double kelvin_;
  }

  /*
   * Returns the internal temp converted to Celsius
   * Formula: k - 273.15
   * @return double - The temperature in Celsius
   */
  double GetTempAsCelsius() const{
   return double kelvin_ - 273.15;
  }

  /*
   * Returns the internal temp converted to Fahrenheit
   * Formula: ((c * 9.0) / 5) + 32;
   * @return double - The temperature in Fahrenheit
   */
   double GetTempAsFahrenheit() const{
   return ((celsius * 9.0) / 5) + 32;
  }

  /*
   * Get a string representation of the temperature.
   * The string will be formatted as:
   * "TEMP UNIT"
   * where TEMP is the temperature to 2 decimal places and UNIT is either
   * "Kelvin", "Celsius", or "Fahrenheit".
   * The conversion to perform is denoted by the parameter.
   * If the unit given through the argument is invalid, set the string to:
   * "Invalid Unit"
   * @uses stringstream
   * @param char unit - The conversion to perform, either 'K', 'C' or 'F',
   *                    defaults to 'K' and is case-insensitive
   * @return string - A string representation of the temperature or invalid if
   *                  the provided unit is not recognized
   */
 string ToString(char unit = 'K') const{
    stringstream ss;
    for (int i = 0; i < 1; i++)
  {
          if (isupper(unit)
      {
          unit = tolower(unit);//This code makes all uppercase characters into lower case characters
          
      }
  }
   

  if (unit == 'k')
  {
   SetTempFromKelvin(double kelvin);
   GetTempAsKelvin();
   ss << "Kelvin " << GetTempAsKelvin();
   string KelvinStr = ss.str();
  
   return KelvinStr;
  }
  else if (unit == 'f')
  {
  SetTempFromFahrenheit(double kelvin);
  GetTempAsFahrenheit();
  ss << "Fahrenheit " << GetTempAsFahrenheit();
   string FahrenheitStr = ss.str();
  return FahrenheitStr;
   
  }
  else if (unit == 'c')
  {
   SetTempFromCelsius(double kelvin);
   GetTempAsCelsius();
   ss << "Celsius " << GetTempAsCelsius();
   string CelsiusStr = ss.str();
   return CelsiusStr;
  }
  else
  {
   SetTempFromKelvin(double kelvin);
   GetTempAsKelvin();
   ss << "Kelvin " << GetTempAsKelvin();
   string KelvinStr = ss.str();
   return KelvinStr;
  }
   
}
    
  
  

 



// REST OF HEADER GUARD GOES HERE
