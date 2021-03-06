#ifndef EXAMDETAILS_CPP_MEDIC_H
#define EXAMDETAILS_CPP_MEDIC_H

#include "Character.h"
#include "Auxiliaries.h"

namespace mtm {
    class Medic : public Character {

    private:
        static const int MAX_MOVEMENT = 5;
        static const int RELOAD_AMOUNT = 5;
        static const int AMMO_PER_ATTACK = 1;

    public:
        //Constructor & Destructor:
        Medic(units_t health, units_t ammo, units_t range, units_t power, Team team);
        ~Medic() = default;
        Medic(const Medic& other) = default;
        Medic& operator=(const Medic& other) = default;

        //Inherited functions
        /// can "attack" also teammates. he heals them.
        void attack(const Point &src_coordinates, const Point &dst_coordinates,
                    std::map<Point, std::shared_ptr<Character>>& board) override;
        std::shared_ptr<Character> clone() const override;
        char getCharCharacterType() const override;
        void reload() override;
        bool isInMovementRange(const Point &src_point, const Point &dst_point) const override;
        void checkAttackExceptions(const Point &src, const Point &dest,
                       const std::map<Point, std::shared_ptr<Character>> &board) override;
    };

}

#endif //EXAMDETAILS_CPP_MEDIC_H
