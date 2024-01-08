# ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "ICharacter.hpp"

class Character : public ICharacter
{
	private:
		std::string name;
		AMateria* inven[4]; // 생성할 땐 empty 초기화
		int size;
		
		static AMateria** floor;
		static int floorSize;
		static int floorCapacity;

		static void floorAdd(AMateria* m);
	public:
		Character();
		Character(std::string const& name);
		Character(const Character& origin);
		Character& operator=(const Character& origin);
		~Character();
		
		std::string const& getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
};

# endif