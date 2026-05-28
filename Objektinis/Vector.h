#pragma once
#ifndef VECTOR_H
#define VECTOR_H

#include <cstddef>
#include <stdexcept>
#include <initializer_list>
#include <utility>

/**
 * @brief Paprastas dinaminio masyvo konteineris, panasus i std::vector.
 *
 * @tparam T Saugomu elementu tipas.
 */
template <typename T>
class Vector
{
private:
	/**
	 * @brief Rodykle i dinamini masyva, kuriame saugomi elementai.
	 */
	T* duomenys_;

	/**
	 * @brief Dabartinis elementu skaicius konteineryje.
	 */
	std::size_t dydis_;

	/**
	 * @brief Rezervuota vieta elementams.
	 */
	std::size_t talpa_;

public:
	/**
	 * @brief Sukuria tuscia Vector konteineri.
	 */
	Vector()
		: duomenys_(nullptr), dydis_(0), talpa_(0)
	{}

	/**
	 * @brief Sukuria Vector konteineri su nurodytu elementu kiekiu.
	 * @param kiekis Pradinis elementu kiekis.
	 */
	Vector(std::size_t kiekis)
		: duomenys_(nullptr), dydis_(kiekis), talpa_(kiekis)
	{
		if (talpa_ > 0)
		{
			duomenys_ = new T[talpa_];
		}
	}

	/**
	 * @brief Sukuria Vector konteineri su nurodytu elementu kiekiu ir pradiniu elementu reiksme.
	 * @param kiekis Pradinis elementu kiekis.
	 * @param reiksme Pradine elementu reiksme.
	 */
	Vector(std::size_t kiekis, const T& reiksme)
		: duomenys_(nullptr), dydis_(kiekis), talpa_(kiekis)
	{
		if (talpa_ > 0)
		{
			duomenys_ = new T[talpa_];

			for (std::size_t i = 0; i < dydis_; ++i)
			{
				duomenys_[i] = reiksme;
			}
		}
	}

	Vector(std::initializer_list<T> sarasas)
		: duomenys_(nullptr), dydis_(sarasas.size()), talpa_(sarasas.size())
	{
		if (talpa_ > 0)
		{
			duomenys_ = new T[talpa_];
			
			std::size_t i = 0;

			for (const T& item : sarasas)
			{
				duomenys_[i] = item;
				++i;
			}
		}
	}
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
	 * @brief Grazina teorini didziausia elementu kieki.
	 * 
	 * @return Didziausias galimas elementu kiekis.
	 */
	std::size_t max_size() const
	{
		return std::numeric_limits<std::size_t>::max() / sizeof(T);
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
		if (naujaTalpa > max_size())
		{
			throw std::length_error("Vector talpa per didele");
		}
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
	 * @brief Keicia konteinerio dydį. Jei naujas dydis yra didesnis už dabartinį, rezervuoja papildomą vietą ir inicializuoja naujus elementus numatytosiomis reikšmėmis.
	 * @param naujasDydis Naujas konteinerio dydis.
	 */
	void resize(std::size_t naujasDydis)
	{
		if (naujasDydis > talpa_)
		{
			reserve(naujasDydis);
		}

		for (std::size_t i = dydis_; i < naujasDydis; ++i)
		{
			duomenys_[i] = T();
		}
		dydis_ = naujasDydis;
	}
	
	/**
	 * @brief Keicia konteinerio dydį. Jei naujas dydis yra didesnis už dabartinį, rezervuoja papildomą vietą ir inicializuoja naujus elementus nurodyta reikšme.
	 * @param naujasDydis Naujas konteinerio dydis.
	 * @param reiksme Reikšmė, su kuria bus inicializuoti nauji elementai,
	 */
	void resize(std::size_t naujasDydis, const T& reiksme)
	{
		if (naujasDydis > talpa_)
		{
			reserve(naujasDydis);
		}

		for (std::size_t i = dydis_; i < naujasDydis; ++i)
		{
			duomenys_[i] = reiksme;
		}
		dydis_ = naujasDydis;
	}


	void shrink_to_fit()
	{
		if (talpa_ == dydis_)
		{
			return;
		}
		if (dydis_ == 0)
		{
			delete[] duomenys_;
			duomenys_ = nullptr;
			talpa_ = 0;
			return;
		}

		T* naujiDuomenys = new T[dydis_];

		for (std::size_t i = 0; i < dydis_; ++i)
		{
			naujiDuomenys[i] = duomenys_[i];
		}

		delete[] duomenys_;
		duomenys_ = naujiDuomenys;
		talpa_ = dydis_;
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
	 * @brief Prideda perkelta elementa i konteinerio pabaiga.
	 * 
	 * @param reiksme Perkeliama reiksme
	 */
	void push_back(T&& reiksme)
	{
		if (dydis_ == talpa_)
		{
			std::size_t naujaTalpa = (talpa_ == 0) ? 1 : talpa_ * 2;
			reserve(naujaTalpa);
		}

		duomenys_[dydis_] = std::move(reiksme);
		++dydis_;
	}

	/**
	 * @brief Sukuria nauja elementa konteinerio pabaigoje;
	 * 
	 * @tparam Args Konstruktoriaus argumentu tipai.
	 * @param args Argumentai, perduodami elemento konstruktoriui.
	 *
	 * @return Nuoroda i naujai sukurta elementa.
	 */
	template <typename... Args>
	T& emplace_back(Args&&... args)
	{
		if (dydis_ == talpa_)
		{
			std::size_t naujaTalpa = (talpa_ == 0) ? 1 : talpa_ * 2;
			reserve(naujaTalpa);
		}

		duomenys_[dydis_] = T(std::forward<Args>(args)...);
		++dydis_;

		return duomenys_[dydis_ - 1];
	}

	/**
	 * @brief Sukuria nauja elementa nurodytoje pozicijoje.
	 * 
	 * @tparam Args Konstruktoriaus argumentu tipai
	 * @param pozicija Iteratorius i vieta, kur bus iterpiamas elementas.
	 * @param args Argumentai, perduodami elemento konstruktoriui.
	 * @return Iteratorius i naujai sukurta elementa.
	 */
	template <typename... Args>
	T* emplace(T* pozicija, Args&&... args)
	{
		std::size_t indeksas = pozicija - duomenys_;

		if (indeksas > dydis_)
		{
			throw std::out_of_range("Vector emplace pozicija uz ribu");
		}
		if (dydis_ == talpa_ )
		{
			std::size_t naujaTalpa = (talpa_ == 0) ? 1 : talpa_ * 2;
			reserve(naujaTalpa);
		}

		for (std::size_t i = dydis_; i > indeksas; --i)
		{
			duomenys_[i] = std::move(duomenys_[i - 1]);
		}

		duomenys_[indeksas] = T(std::forward<Args>(args)...);
		++dydis_;

		return duomenys_ + indeksas;

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
	
	T* insert(T* pozicija, const T& reiksme)
	{
		std::size_t indeksas = pozicija - duomenys_;

		if (indeksas > dydis_)
		{
			throw std::out_of_range("Insert position out of range");
		}

		if (dydis_ >= talpa_)
		{
			reserve(talpa_ == 0 ? 1 : talpa_ * 2);
		}

		for (std::size_t i = dydis_; i > indeksas; --i)
		{
			duomenys_[i] = duomenys_[i - 1];
		}
		duomenys_[indeksas] = reiksme;
		++dydis_;

		return duomenys_ + indeksas;
	}

	/**
	 * @brief Iterpia kelias vienodas reikses pries nurodyta pozicija.
	 * 
	 * @param pozicija Iteratorius i vieta, pries kuria iterpiama.
	 * @param kiekis Kiek elementu iterpti
	 * @param reiksme Iterpiama reiksme
	 * @return Iteratorius i pirma iterpta elementa.
	 */
	T* insert(T* pozicija, std::size_t kiekis, const T& reiksme)
	{
		std::size_t indeksas = pozicija - duomenys_;

		if (indeksas > dydis_)
		{
			throw std::out_of_range("Insert position out of range");
		}

		if (kiekis == 0)
		{
			return duomenys_ + indeksas;
		}

		if (dydis_ + kiekis > talpa_)
		{
			std::size_t naujaTalpa = (talpa_ == 0) ? 1 : talpa_;

			while (naujaTalpa < dydis_ + kiekis)
			{
				naujaTalpa *= 2;
			}

			reserve(naujaTalpa);
		}
		
		for (std::size_t i = dydis_; i > indeksas; --i)
		{
			duomenys_[i + kiekis - 1] = duomenys_[i - 1];
		}

		for (std::size_t i = 0; i < kiekis; i++)
		{
			duomenys_[indeksas + i] = reiksme;
		}
		
		dydis_ += kiekis;

		return duomenys_ + indeksas;
	}

	/**
	 * @brief Iterpia inicializavimo saraso elementus pries nurodyta pozicija
	 * 
	 * @param pozicija Iteratorius i vieta, pries kuria iterpiama
	 * @param sarasas Iterpiamos reiksmes
	 * @return Iteratorius i pirma iterpta elementa
	 */
	T* insert(T* pozicija, std::initializer_list<T> sarasas)
	{
		std::size_t indeksas = pozicija - duomenys_;
		std::size_t kiekis = sarasas.size();

		if (indeksas > dydis_)
		{
			throw std::out_of_range("Insert position out of range");
		}

		if (kiekis == 0)
		{
			return duomenys_ + indeksas;
		}

		if (dydis_ + kiekis > talpa_)
		{
			std::size_t naujaTalpa = (talpa_ == 0) ? 1 : talpa_;

			while (naujaTalpa < dydis_ + kiekis)
			{
				naujaTalpa *= 2;
			}
			reserve(naujaTalpa);
		}
		for (std::size_t i = dydis_ ; i > indeksas; --i )
		{
			duomenys_[i + kiekis - 1] = duomenys_[i - 1];
		}

		std::size_t i = 0;

		for (const T& reiksme : sarasas)
		{
			duomenys_[indeksas + i] = reiksme;
			++i;
		}
		dydis_ += kiekis;

		return duomenys_ + indeksas;
	}

	/**
	 * @brief Pasalina elementa is nurodytos pozicijos.
	 * @param pozicija Iteratoriaus i salinama elementa
	 * @return Iteratorius i elementa po pasalinto elemento
	 */
	T* erase(T* pozicija)
	{
		std::size_t indeksas = pozicija - duomenys_;
		
		if (indeksas >= dydis_)
		{
			throw std::out_of_range("Erase position out of range");
		}

		for (std::size_t i = indeksas; i < dydis_ - 1; ++i)
		{
			duomenys_[i] = duomenys_[i + 1];
		}

		--dydis_;
		return duomenys_ + indeksas;
	}

	/**
	 * @brief Pasalina elementus is nurodytos pozicijos intervalo.
	 * @param pirma Iteratorius i pirma salinama elementa
	 * @param paskutine Iteratorius uz paskutinio salinamo elemento
	 * @return Iteratorius i vieta, kurioje prasideda pasalintas intervalas
	 */
	T* erase(T* pirma, T* paskutine)
	{
		std::size_t pradzia = pirma - duomenys_;
		std::size_t pabaiga = paskutine - duomenys_;

		if (pradzia > pabaiga || pabaiga > dydis_)
		{
			throw std::out_of_range("Erase range out of range");
		}

		std::size_t kiekSalinti = pabaiga - pradzia;

		for (std::size_t i = pradzia; i + kiekSalinti < dydis_; ++i)
		{
			duomenys_[i] = duomenys_[i + kiekSalinti];
		}
		dydis_ -= kiekSalinti;
		return duomenys_ + pradzia;
	}

	/**
	 * @brief Apkeicia du Vector konteinerio duomenis.
	 * @param kitas Kitas Vector konteineris, su kuriuo keciami duomenys.
	 */
	void swap(Vector& kitas) noexcept
	{
		T* laikiniDuomenys = duomenys_;
		duomenys_ = kitas.duomenys_;
		kitas.duomenys_ = laikiniDuomenys;

		std::size_t laikinasDydis = dydis_;
		dydis_ = kitas.dydis_;
		kitas.dydis_ = laikinasDydis;

		std::size_t laikinaTalpa = talpa_;
		talpa_ = kitas.talpa_;
		kitas.talpa_ = laikinaTalpa;
	}

	/**
	 *@brief Palygina du Vector objektus
	 *@param kitas Kitas Vector objektas, su kuriuo bus lyginamas esamas objektas
	 *@return true jeigu dydis ir visi elementai sutampa.
	*/
	bool operator==(const Vector& kitas) const
	{
		if (dydis_ != kitas.dydis_)
		{
			return false;
		}

		for (std::size_t i = 0; i < dydis_; ++i)
		{
			if (duomenys_[i] != kitas.duomenys_[i])
			{
				return false;
			}
		}
		return true;
	}
	/**
	 * @brief Palygina du Vector objektus.
	 * @param kitas Kitas Vector objektas, su kuriuo bus lyginamas esamas objektas.
	 * @return true jeigu dydis arba bent vienas elementas nesutampa.
	 */
	bool operator!=(const Vector& kitas) const
	{
		return !(*this == kitas);
	}

	/**
	 * @brief Pakeicia Vector turinti nurodytu kiekiu vienodu elementu.
	 * 
	 * @param kiekis Naujai priskiriamų elementų kiekis.
	 * @param reiksme Reikšmė, kuria bus priskirti nauji elementai.
	 */
	void assign(std::size_t kiekis, const T& reiksme)
	{
		if (kiekis > talpa_)
		{
			delete[] duomenys_;
			duomenys_ = new T[kiekis];
			talpa_ = kiekis;
		}
		for (std::size_t i = 0; i < kiekis; ++i)
		{
			duomenys_[i] = reiksme;
		}
		dydis_ = kiekis;
	}

	/**
	 * @brief Pakeicia Vector turini inicializavimo list
	 * @param sarasas Naujos elementu reiksmes
	 */
	void assign(std::initializer_list<T> sarasas)
	{
		if (sarasas.size() > talpa_)
		{
			delete[] duomenys_;
			duomenys_ = new T[sarasas.size()];
			talpa_ = sarasas.size();
		}

		std::size_t i = 0;
		for (const T& reiksme : sarasas)
		{
			duomenys_[i] = reiksme;
			++i;
		}
		dydis_ = sarasas.size();

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

	/**
	 * @brief Perkelia vieno Vector objekto duomenis i kita Vector objektas.
	 * 
	 * @param kitas Vector objektas, kurio duomenys bus perkelti.
	 * @return nuoroda si Vector objekta.
	 */
	Vector& operator=(Vector&& kitas) noexcept
	{
		if (this != &kitas)
		{
			delete[] duomenys_;

			duomenys_ = kitas.duomenys_;
			dydis_ = kitas.dydis_;
			talpa_ = kitas.talpa_;

			kitas.duomenys_ = nullptr;
			kitas.dydis_ = 0;
			kitas.talpa_ = 0;
		}
		return *this;
	}

	/**
	 * @brief Priskira Vector turini is inicializavimo saraso.
	 * 
	 * @param sarasas Naujos elementu reiksmes
	 * @return nuoroda i si Vector objekta,
	 */
	Vector& operator=(std::initializer_list<T> sarasas)
	{
		if (sarasas.size() > talpa_);
		{
			delete[] duomenys_;
			duomenys_ = new T[sarasas.size()];
			talpa_ = sarasas.size();
		}

		std::size_t i = 0;
		for (const T& reiksme : sarasas)
		{
			duomenys_[i] = reiksme;
			i++;
		}

		dydis_ = sarasas.size();
		return *this;

	}
};

#endif