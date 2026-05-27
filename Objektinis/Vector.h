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
	 * @brief Grazina rodykle i saugomu elementu masyva.
	 */
	T* data()
	{
		return duomenys_;
	}
	/**
	 * @brief Grazina rodykle i saugomu elementu masyva.
	 */
	const T* data() const
	{
		return duomenys_;
	}
	/**
	 * @brief Grazina iteratoriu i pirma elementa.
	 */
	T* begin()
	{
		return duomenys_;
	}
	/**
	 * @brief Grazina const iteratoriu i pirma elementa.
	 */
	const T* begin() const
	{
		return duomenys_;
	}
	/**
	 * @brief Grazina iteratoriu uz paskutinio elemento.
	 */
	T* end()
	{
		return duomenys_ + dydis_;
	}
	/**
	 * @brief Grazina const iteratoriuuz paskutinio elemento.
	 */
	const T* end() const
	{
		return duomenys_ + dydis_;
	}
	/**
	 * @brief Grazina const iteratoriu i pirma elementa.
	 */
	const T* cbegin() const
	{
		return duomenys_;
	}
	/**
	 * @brief Grazina const iteratoriu uz paskutinio elemento.
	 */
	const T* cend() const
	{
		return duomenys_ + dydis_;
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

	/**
	 * @brief Grazina pirma elementa.
	 */
	T& front()
	{
		if (empty())
		{
			throw std::out_of_range("Vector is empty");
		}
		return duomenys_[0];
	}

	/**
	 *
	 * @brief Grazina pirma elementa.
	 */
	const T& front() const
	{
		if (empty())
		{
			throw std::out_of_range("Vector is empty");
		}
		return duomenys_[0];
	}
	/**
	 * @brief Grazina paskutini elementa.
	 */
	T& back()
	{
		if (empty())
		{
			throw std::out_of_range("Vector is empty");
		}
		return duomenys_[dydis_ - 1];
	}
	/**
	 * @brief Grazina paskutini elementa.
	 */
	const T& back() const
	{
		if (empty())
		{
			throw std::out_of_range("Vector is empty");
		}
		return duomenys_[dydis_ - 1];
	}

	/**
	 * @brief Rezervuoja vietos nurodytam elemetu kiekiui.
	 *
	 *  Jei nauja talpa yra mazesne arba lygi dabartinei, nieko nedaro.
	 */
	void reserve(std::size_t naujaTalpa)
	{
		if (naujaTalpa <= talpa_)
		{
			return;
		}
		T* naujiDuomenys = new T[naujaTalpa];

		for (std::size_t i = 0; i < dydis_; ++i)
		{
			naujiDuomenys[i] = duomenys_[i];
		}
		delete[] duomenys_;
		duomenys_ = naujiDuomenys;
		talpa_ = naujaTalpa;
	}
	/**
	 * @brief Prideda elementa i konteinerio pabaiga.
	 */

	void push_back(const T& reiksme)
	{
		if (dydis_ >= talpa_)
		{
			reserve(talpa_ == 0 ? 1 : talpa_ * 2);
		}
		duomenys_[dydis_] = reiksme;
		++dydis_;
	}
	/**
	 * @brief pasalina paskutini elementa.
	 */
	void pop_back()
	{
		if (empty())
		{
			throw std::out_of_range("Vector is empty");
		}
		--dydis_;
	}
	/**
	 * @brief Pasalina visus elementus, bet palieka rezervuota talpa.
	 */
	void clear()
	{
		dydis_ = 0;
	}
	/**
	 * @brief Kopijuoja vieno Vector objekto duomenis i kita Vector objektas.
	 * @param kitas Kopijuojamas Vector objektas
	 */
	Vector(const Vector& kitas)
		: duomenys_(nullptr), dydis_(kitas.dydis_), talpa_(kitas.talpa_)
	{
		if (kitas.talpa_ > 0)
		{
			duomenys_ = new T[talpa_];

			for (std::size_t i = 0; i < kitas.dydis_; ++i)
			{
				duomenys_[i] = kitas.duomenys_[i];
			}
		}
	}

	/**
	 * @brief Priskiria vieno Vector objekto duomenis kitam Vector objektui.
	 * @param kitas Kopijuojamas Vector objektas
	 * @return nuoroda si Vector objekta.
	 */
	Vector& operator=(const Vector& kitas)
	{
		if (this != &kitas)
		{
			T* naujiDuomenys = nullptr;

			if (kitas.talpa_ > 0)
			{
				naujiDuomenys = new T[kitas.talpa_];

				for (std::size_t i = 0; i < kitas.dydis_; ++i)
				{
					naujiDuomenys[i] = kitas.duomenys_[i];
				}
			}

			delete[] duomenys_;
			
			duomenys_ = naujiDuomenys;
			dydis_ = kitas.dydis_;
			talpa_ = kitas.talpa_;
		}
		return *this;
	}
	/**
	 * @brief Perkelia vieno Vector objekto duomenis i kita Vector objektas.
	 * @param kitas Vector objektas, kurio duomenys bus perkelti.
	 */
	Vector(Vector&& kitas) noexcept
		: duomenys_(kitas.duomenys_), dydis_(kitas.dydis_), talpa_(kitas.talpa_)
	{
		kitas.duomenys_ = nullptr;
		kitas.dydis_ = 0;
		kitas.talpa_ = 0;
	}
};

#endif