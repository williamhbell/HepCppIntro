/* W. H. Bell
** A charged track container
*/

#ifndef TRACK_CONTAINER_HH
#define TRACK_CONTAINER_HH

template <class T> class TrackContainer {
public:
  TrackContainer();
  T pt, costheta, phi0, d0, z0;
};

/* Template instantiations needed by g++ */
template class TrackContainer<float>;
template class TrackContainer<double>;

#endif
