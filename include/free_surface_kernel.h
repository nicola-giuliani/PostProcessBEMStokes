#ifndef __mathlab__free_surface_kernel_h // Avoid double definitions
#define __mathlab__free_surface_kernel_h

#include <deal.II/base/types.h>
#include <deal.II/base/utilities.h>
#include <cmath>
#include <kernel.h>

DEAL_II_NAMESPACE_OPEN

template <int dim>
class FreeSurfaceStokesKernel : public StokesKernel<dim>
{
public:
  FreeSurfaceStokesKernel(const double eps = 0.);

  virtual Tensor<2, dim, double>
  value_tens_image(const Tensor<1,dim,double> &p, const Tensor<1,dim,double> &p_image) const;
  virtual Tensor<2, dim, double>
  value_tens_image_old(const Tensor<1,dim,double> &p, const Tensor<1,dim,double> &p_image) const;
  virtual Tensor<3, dim, double>
  value_tens_image2(const Tensor<1,dim,double> &p, const Tensor<1,dim,double> &p_image) const;
  virtual Tensor<3, dim, double>
  value_tens_image2_old(const Tensor<1,dim,double> &p, const Tensor<1,dim,double> &p_image) const;
  virtual Tensor<2, dim, double>
  value_tens_image_pimponi(const Tensor<1,dim,double> &p, const Tensor<1,dim,double> &p_image) const;
  virtual Tensor<3, dim, double>
  value_tens_image2_pimponi(const Tensor<1,dim,double> &p, const Tensor<1,dim,double> &p_image) const;


  void set_wall_orientation(const unsigned int orientation);

  unsigned int  get_wall_orientation();

private:
  const double epsilon;
  double wall_position;
  unsigned int wall_orientation;
};

DEAL_II_NAMESPACE_CLOSE

#endif
