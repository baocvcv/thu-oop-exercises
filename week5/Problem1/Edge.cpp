#include "Edge.h"

const double Edge::mu = 1e-6;

bool Edge::compare_to(Edge f){
    if(weight - f.weight > mu) return true;
    if(weight - f.weight < -mu) return false;
    if(v > f.v) return true;
    if(v < f.v) return false;
    if(w > f.w) return true;
    if(w < f.w) return false;
    return false;
}

bool Edge::compare(Edge e, Edge f){
    if(e.weight - f.weight > mu) return true;
    if(e.weight - f.weight < -mu) return false;
    if(e.v > f.v) return true;
    if(e.v < f.v) return false;
    if(e.w > f.w) return true;
    if(e.w < f.w) return false;
    return false;
}

