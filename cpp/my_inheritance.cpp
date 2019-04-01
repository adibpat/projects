#include <iostream>
#include <string.h>

using namespace std;
typedef enum Color
{
 RED = 0,
 BLUE,
 GREEN,
 WHITE,
 BLACK,
 GREY,
 MAX_COLOR,
} Color;

class car {
protected:
    int vin;
    void print_vin() { cout << vin; }
private:
    string brand, model;
    int price, fuel_type, engine, capacity;
    Color color;
public:
    car ()
        : brand("Default"), model("Default"), price(0), fuel_type(0), engine(0), color(MAX_COLOR), capacity(0) {}

    car (string br, string mod, int p, int ftype, int eng, Color c, int cap)
        : brand(br), model(mod), price(p), fuel_type(ftype), engine(eng), color(c), capacity(cap) {}

    /* Setters */
    void set_brand (string b) { brand = b; }
    void set_model (string m) { model = m; }
    void set_price (int p) { price = p; }
    void set_fuel_type (int ftype) { fuel_type = ftype; }
    void set_engine (int e) { engine = e; }
    void set_color (Color c) { color = c; }
    void set_capacity (int cap) { capacity = cap; }
    void set_vin (int v) { vin = v; }

    /* Getters */
    int get_vin() { return (vin); }
    void print_car_vin() { print_vin(); }
    string get_brand() { return (brand); }
    string get_model() { return (model); }
    int get_price () { return (price); }
    int get_fuel_type () { return(fuel_type); }
    int get_engine () { return(engine); }
    Color get_color () { return(color); }
    int get_capacity () { return(capacity); }
};

class luxury_car : public car {
    int transmission_type;
public:
    void set_transmission (int t) { transmission_type = t; }

    /* Setters */
    void set_lcolor(Color c) { set_color(c); }
    void set_lvin(int v) { set_vin(v); }

    /* Getters */
    string get_lbrand() { return (get_brand()); }
    string get_lmodel() { return (get_model()); }
    Color get_lcolor() { return(get_color()); }
    int get_lvin() { return (get_vin()); }
};

class sports_car : private car { // must have 'class car' defined first to be used as Base
    int horse_power;
    int f1_ranking;
public:
    sports_car (string br, string mod, int p, int ftype, int eng, Color c, int cap, int hp, int rank)
        : car(br, mod, p, ftype, eng, c, cap), horse_power(hp), f1_ranking(rank) {}

    /* Setters */
    void set_hp (int hp) { horse_power = hp; }
    void set_f1_ranking (int rank) { f1_ranking = rank; }
    void set_scolor(Color c) { set_color(c); }
    void set_svin(int v) { set_vin(v); }

    /* Getters */
    string get_sbrand() { return (get_brand()); }
    string get_smodel() { return (get_model()); }
    Color get_scolor() { return(get_color()); }
    int get_svin() { return (get_vin()); }
};

class vintage_car : protected car {
    int year;
    
public:
    vintage_car (string br, string mod, int p, int ftype, int eng, Color c, int cap, int yr)
        : car(br, mod, p, ftype, eng, c, cap), year(yr) {}
    void set_vintage_vin (int v) { set_vin(v); }
    void set_vcolor(Color c) { set_color(c); }
    void set_vvin(int v) { set_vin(v); }
    string get_vbrand() { return (get_brand()); }
    string get_vmodel() { return (get_model()); }
    Color get_vcolor() { return(get_color()); }
    int get_vvin() { return (get_vin()); }    
};

int main ()
{
    car c("Audi", "A3", 40000, 0, 0, GREY, 4);
    c.set_vin(9001);
    cout << c.get_brand() << " " << c.get_model() << "'s VIN is: "; c.print_car_vin() /*<< c.get_vin()*/ ;
    cout << endl;

    /* public inheritance */
    luxury_car l;
    //l.price = 1000000; Wrong - private members are still private
    l.set_brand("Rolce-Royce"); // has direct access to public members
    l.set_model("A1");
    l.set_vin(9000);
    
    
    sports_car s("Audi", "S3", 40000, 0, 0, GREY, 4, 200, 24);
    //s.set_color(BLUE); Wrong - have no access to private members 
    s.set_scolor(BLUE); // public members of a class can call private members
    s.set_svin(9002);
    cout << s.get_sbrand() << " " << s.get_smodel() << "'s color is " << s.get_scolor() << endl;
    cout << s.get_sbrand() << " " << s.get_smodel() << "'s VIN is: " << s.get_svin();
    cout << endl;

    vintage_car v("Porsche", "911", 40000, 0, 0, GREY, 4, 1954);
    v.set_vvin(9002);
    return (0);
}
