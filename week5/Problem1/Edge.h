#pragma once

class Edge{
    int v;
    int w;
    double weight;
    static const double mu;

    public:
    Edge(int _v, int _w, double _weight = -1.0): v(_v), w(_w), weight(_weight) {};

    void set_v(int _v) { v = _v; }
    void set_w(int _w) { w = _w; }
    void set_weight(double _weight) { weight = _weight; }
    int get_v() const { return v; }
    int get_w() const { return w; }
    double get_weight() const { return weight; }

    int get_other(int vertex){
        if (vertex == v) return w;
        else return v;
    };

    bool compare_to(Edge f);
    static bool compare(Edge e, Edge f);
};