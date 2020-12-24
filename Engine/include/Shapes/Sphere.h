#pragma once
#include <Shapes/Shape.h>
#include <memory>

class Sphere : public Shape , public std::enable_shared_from_this<Sphere> {
public:
    static std::shared_ptr<Sphere> createSphere();

    bool operator==(const Shape &other) const override;

    void setTransform(const Matrix &m) override;
    Matrix getTransform() const override;
    Matrix getInverseTransform() const override;

    void setMaterial(const Material &m) override;
    Material& getMaterial() override;
    Material getMaterial() const override;

    Tuple normalAt(const Tuple &point) const override;
    std::vector<Intersection> intersects(const Ray &r) const override;

private:
    Matrix transform;
    Matrix inverseTransform;
    Material material;

    Sphere();
};