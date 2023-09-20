#include "point.hpp"

namespace geometry 
{
        class vector_t
        {
                public:
                        double x = 0;
                        double y = 0;
                        double z = 0;

                        vector_t () = default;
                        vector_t (const point_t &begin_, const point_t &end_)
                        {
                                if (begin_.get_status() == INVALID || end.get_status() == INVALID)
                                        ERROR_EXIT(INVALID_POINT, "Point has invalid coordinates.");

                                x = end_.x - begin_.x;
                                y = end_.y - begin_.y;
                                z = end_.z - begin_.z;
                        };

                        ~vector_t () {};

                        void print_vector ()
                        {
                                std::cout << "[" << x << ", " <<
                                                    y << ", " <<
                                                    z << "]\n";
                        }
        }
}

