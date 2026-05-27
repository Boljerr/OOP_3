#pragma once
#ifndef VECTOR_H
#define VECTOR_H

#include <cstddef>
#include <stdexcept>

/**
 * @brief Paprastas dinaminio masyvo konteineris, panasus i std::vector.
 *
 * @tparam T Saugomu elementu tipas.
 */
template <typename T>
class Vector
{
private:
    T* duomenys_;
    std::size_t dydis_;
    std::size_t talpa_;

public:
    /**
     * @brief Sukuria tuscia Vector konteineri.
     */
    Vector()
        : duomenys_(nullptr), dydis_(0), talpa_(0)
    {}

    /**
     * @brief Atlaisvina konteinerio naudojama atminti.
     */
    ~Vector()
    {
        delete[] duomenys_;
    }

    /**
     * @brief Grazina elementu kieki.
     */
    std::size_t size() const
    {
        return dydis_;
    }

    /**
     * @brief Grazina rezervuotos vietos kieki.
     */
    std::size_t capacity() const
    {
        return talpa_;
    }

    /**
     * @brief Patikrina, ar konteineris tuscias.
     */
    bool empty() const
    {
        return dydis_ == 0;
    }

    /**
     * @brief Grazina elementa pagal indeksa be ribu tikrinimo.  
     */
    T& operator[](std::size_t index)
	{
		return duomenys_[index];
	}

    /**
	 * @brief Grazina elementa pagal indeksa be ribu tikrinimo.
     */
    const T& operator[](std::size_t index) const
	{
		return duomenys_[index];
	}

	/**
	 * @brief Grazina elementa pagal indeksa su ribu tikrinimu.
	 */
    T& at(std::size_t index)
    {
		if (index >= dydis_)
		{
			throw std::out_of_range("Index out of range");
		}
        return duomenys_[index];
    }

    /**
     * @brief Grazina elementa pagal indeksa su ribu tikrinimu 
	 */
    const T& at(std::size_t index) const
    {
	    if (index >= dydis_)
	    {
		    throw std::out_of_range("Index out of range");
	    }
        return duomenys_[index];
    }


};

#endif