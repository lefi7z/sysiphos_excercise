#include <string>
#include <iostream>


namespace sysiphos {

    /**
     * Der 'Hersteller' wird hier als abstract base class modelliert.
     * Um einen neuen anzulegen, muss in der abgeleiteten Klasse die
     * Methode/property 'get_name()' mit dem Namen des Herstellers
     * ueberschrieben werden.
     *
     * Der Hersteller wird dann spaeter dem jeweiligen Fahrzeug 
     * eingetragen. Dies folgt dem Prinzip der *dependency injection*.
     */
    class Manufacturer {

        public:
            virtual std::string get_name() =0;
    };

    /* ------ die Hersteller -------- */

    class Honda : public Manufacturer {

        public:
            std::string get_name() { return "Honda"; }
    };

    class KTM : public Manufacturer {

        public:
            std::string get_name() { return "KTM"; }
    };

    class Toyota : public Manufacturer {

        public:
            std::string get_name() { return "Toyota"; }
    };

    /**
     * Die Basisklasse fuer Fahrzeuge. Jedes Fahrzeug ist von einem Typ, 
     * welcher einfach in der abgeleiteten Klasse neu eingetragen wird.
     */
    class Vehicle {

        protected:
            Manufacturer* manu;
            std::string type = "vehicle";

        public:
            Vehicle(Manufacturer* m)
                : manu(m) { }

            void Move() {
                std::cout << "You are driving a " << this->type << " from " << manu->get_name() << "." << std::endl;
            }
    };

    /**
     * Die Klasse 'Car' soll noch Reifen mit speziellen Eigenschaften bekommen.
     */
    class Tyre {
        public:
            double Pressure_bar = 2.5;
    };

    class SummerTyre : public Tyre {
        public:
            double MaximumTemperature_degC = 50.;
    };

    class WinterTyre : public Tyre {
        public:
            double MinimumTemperature_degC = -45.;
            double Thickness_mm = 7.;
    };


    /* ------ die Fahrzeugtypen --------- */

    class Car : public Vehicle {

            Tyre* tyre;

        public:
            Car(Manufacturer* manu, Tyre* t)
                : Vehicle(manu), tyre(t) { this->type = "car"; }

            /**
             * Die "default-factory" stattet neue Autos mit Sommerreifen aus:
             */
            Car(Manufacturer* manu)
                : Car(manu, new SummerTyre) { }

            void switch_tyres(Tyre* t)
            {
                this->tyre = t;
            }
    };

    class Motorcycle : public Vehicle {

        public:
            Motorcycle(Manufacturer* manu)
                : Vehicle(manu) { this->type = "motorcycle"; }
    };

} // namespace
