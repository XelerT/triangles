
namespace geometry
{
        // Plane in form of A * x + B * y + C * z + D = 0;
        class plane_t
        {
                public:
                        double A = 0;
                        double B = 0;
                        double C = 0;
                        double D = 0;
        
                        plane_t (point_t &point, vector_t &first_vector, vector_t &second_vector)
                        {
                                if (vertex_.get_status() == INVALID)
                                        ERROR_EXIT(INVALID_POINT, "Point has invalid coordinates.");

                                A =   first_vector.y * second_vector.z - second_vector.y * first_vector.z;
                                B = -(first_vector.x * second_vector.z - second_vector.x * first_vector.z);
                                C =   first_vector.x * second_vector.y - second_vector.x * first_vector.y;

                                D = - A * point.x - B * point.y - C * point.z; 
                        }
        }
}