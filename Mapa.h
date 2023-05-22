class Mapa
{
private:
    int ancho;
    int alto;
public:
    void crearMapa();
    void agregarPersonaje();
    void eliminaPersonaje();
    Mapa(int, int);
    ~Mapa();
};