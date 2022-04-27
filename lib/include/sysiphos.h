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

    class KTM : public Manufacturer {

        public:
            std::string get_name() { return "KTM"; }
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
                std::cout << "You are driving a " << this->type << " from " << manu->get_name() << std::endl;
            }
    };

    /* ------ die Fahrzeugtypen --------- */

    class Car : public Vehicle {

        public:
            Car(Manufacturer* manu)
                : Vehicle(manu) { this->type = "car"; }
    };

    class Motorcycle : public Vehicle {

        public:
            Motorcycle(Manufacturer* manu)
                : Vehicle(manu) { this->type = "motorcycle"; }
    };

} // namespace
