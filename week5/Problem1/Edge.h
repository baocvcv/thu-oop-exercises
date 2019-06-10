#pragma once

/**
 * Edge class.
 * Stores an edge and supports basic operations.
 */
class Edge{
    /// One vertex of the edge.
    int v;

    /// Another vertec of the edge.
    int w;

    /// Weight of the edge.
    double weight;

    /// Constant used in compare()
    static const double mu;

    public:
    /**
     * @brief Construct a new Edge object
     * 
     * @param _v a vertex
     * @param _w another vertex
     * @param _weight weight of the edge
     */
    Edge(int _v, int _w, double _weight = -1.0): v(_v), w(_w), weight(_weight) {};

    /**
     * @brief Set the v object
     * 
     * @param _v 
     */
    void set_v(int _v) { v = _v; }

    /**
     * @brief Set the w object
     * 
     * @param _w 
     */
    void set_w(int _w) { w = _w; }

    /**
     * @brief Set the weight object
     * 
     * @param _weight 
     */
    void set_weight(double _weight) { weight = _weight; }

    /**
     * @brief Get the v object
     * 
     * @return int 
     */
    int get_v() const { return v; }

    /**
     * @brief Get the w object
     * 
     * @return int 
     */
    int get_w() const { return w; }

    /**
     * @brief Get the weight object
     * 
     * @return double 
     */
    double get_weight() const { return weight; }

    /**
     * @brief Get the other vertex
     * 
     * @param vertex 
     * @return int the id of the other vertex
     */
    int get_other(int vertex){
        if (vertex == v) return w;
        else return v;
    };

    /**
     * @brief Compare with another edge.
     * 
     * @param f 
     * @return true weight is smaller
     * @return false 
     */
    bool compare_to(Edge f);

    /**
     * @brief Compare two edges.
     * 
     * @param e 
     * @param f 
     * @return true 
     * @return false 
     */
    static bool compare(Edge e, Edge f);
};