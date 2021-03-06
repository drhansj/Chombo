#ifdef CH_LANG_CC
/*
 *      _______              __
 *     / ___/ /  ___  __ _  / /  ___
 *    / /__/ _ \/ _ \/  V \/ _ \/ _ \
 *    \___/_//_/\___/_/_/_/_.__/\___/
 *    Please refer to Copyright.txt, in Chombo's root directory.
 */
#endif

#ifndef _DIVNORMALREFINEMENT_H_
#define _DIVNORMALREFINEMENT_H_

#include "RefinementCriterion.H"

#include "NamespaceHeader.H"

///
/**
   This refinement criterion refines if the change in the normal exceeds a threshold.
 */
template <int dim> class DivNormalRefinement: public RefinementCriterion<dim>
{
public:
  /// Null constructor
  DivNormalRefinement();

  /// Constructor which sets a threshold
  DivNormalRefinement(const Real & a_maxChangeThreshold,
                      const int  & a_maxNumberOfRefinements);

  /// Destructor
  virtual ~DivNormalRefinement();

  /**
     Refine if the change in the normal exceeds a threshold.
   */
  virtual bool doRefine(IndexTM<int,dim>          & a_refineInDir,
                        const CutCellMoments<dim> & a_ccm,
                        const int                 & a_numberOfRefinements);

  /**
     Estimate the change in the normal.
   */
  virtual Real approximateDivNormal(const CutCellMoments<dim> & a_ccm);

  // Set threshold
  virtual void setMaxChangeThreshold(const Real & a_maxChangeThreshold);

  /// Get threshold
  virtual Real getMaxChangeThreshold();

// Set max number of refinements
  virtual void setMaxNumberOfRefinements(const int & a_maxNumberOfRefinements);

  /// Get threshold
  virtual int getMaxNumberOfRefinements();

protected:
  Real m_maxChangeThreshold;
  int  m_maxNumberOfRefinements;
};

#include "NamespaceFooter.H"

#include "DivNormalRefinementImplem.H"

#endif

