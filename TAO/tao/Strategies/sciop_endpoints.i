// $Id$
//
// ******  Code generated by the The ACE ORB (TAO) IDL Compiler *******
// TAO and the TAO IDL Compiler have been developed by the Center for
// Distributed Object Computing at Washington University, St. Louis.
//
// Information about TAO is available at:
//                 http://www.cs.wustl.edu/~schmidt/TAO.html

// *************************************************************
// Inline operations for class TAO_SCIOP_Endpoint_Info_var
// *************************************************************

#if !defined (TAO_USE_SEQUENCE_TEMPLATES)

#if !defined (__TAO_UNBOUNDED_SEQUENCE_TAO_SCIOPENDPOINTSEQUENCE_CI_)
#define __TAO_UNBOUNDED_SEQUENCE_TAO_SCIOPENDPOINTSEQUENCE_CI_

  // = Static operations.
  ACE_INLINE TAO_SCIOP_Endpoint_Info *
  _TAO_Unbounded_Sequence_TAO_SCIOPEndpointSequence::allocbuf (CORBA::ULong size)
  // Allocate storage for the sequence.
  {
    TAO_SCIOP_Endpoint_Info *retval = 0;
    ACE_NEW_RETURN (retval, TAO_SCIOP_Endpoint_Info[size], 0);
    return retval;
  }

  ACE_INLINE void _TAO_Unbounded_Sequence_TAO_SCIOPEndpointSequence::freebuf (TAO_SCIOP_Endpoint_Info *buffer)
  // Free the sequence.
  {
    delete [] buffer;
  }

  ACE_INLINE
  _TAO_Unbounded_Sequence_TAO_SCIOPEndpointSequence::_TAO_Unbounded_Sequence_TAO_SCIOPEndpointSequence (void) // Default constructor.
  {
  }

  ACE_INLINE
  _TAO_Unbounded_Sequence_TAO_SCIOPEndpointSequence::_TAO_Unbounded_Sequence_TAO_SCIOPEndpointSequence (CORBA::ULong maximum) // Constructor using a maximum length value.
    : TAO_Unbounded_Base_Sequence (maximum, _TAO_Unbounded_Sequence_TAO_SCIOPEndpointSequence::allocbuf (maximum))
  {
  }

  ACE_INLINE
  _TAO_Unbounded_Sequence_TAO_SCIOPEndpointSequence::_TAO_Unbounded_Sequence_TAO_SCIOPEndpointSequence (CORBA::ULong maximum,
    CORBA::ULong length,
    TAO_SCIOP_Endpoint_Info *data,
    CORBA::Boolean release)
  : TAO_Unbounded_Base_Sequence (maximum, length, data, release)
  {
  }

  ACE_INLINE
  _TAO_Unbounded_Sequence_TAO_SCIOPEndpointSequence::_TAO_Unbounded_Sequence_TAO_SCIOPEndpointSequence (const _TAO_Unbounded_Sequence_TAO_SCIOPEndpointSequence &rhs)
  // Copy constructor.
    : TAO_Unbounded_Base_Sequence (rhs)
  {
    if (rhs.buffer_ != 0)
    {
      TAO_SCIOP_Endpoint_Info *tmp1 = _TAO_Unbounded_Sequence_TAO_SCIOPEndpointSequence::allocbuf (this->maximum_);
      TAO_SCIOP_Endpoint_Info * const tmp2 = ACE_reinterpret_cast (TAO_SCIOP_Endpoint_Info * ACE_CAST_CONST, rhs.buffer_);

      for (CORBA::ULong i = 0; i < this->length_; ++i)
        tmp1[i] = tmp2[i];

      this->buffer_ = tmp1;
    }
    else
    {
      this->buffer_ = 0;
    }
  }

  ACE_INLINE _TAO_Unbounded_Sequence_TAO_SCIOPEndpointSequence &
  _TAO_Unbounded_Sequence_TAO_SCIOPEndpointSequence::operator= (const _TAO_Unbounded_Sequence_TAO_SCIOPEndpointSequence &rhs)
  // Assignment operator.
  {
    if (this == &rhs)
      return *this;

    if (this->release_)
    {
      if (this->maximum_ < rhs.maximum_)
      {
        // free the old buffer
        TAO_SCIOP_Endpoint_Info *tmp = ACE_reinterpret_cast (TAO_SCIOP_Endpoint_Info *, this->buffer_);
        _TAO_Unbounded_Sequence_TAO_SCIOPEndpointSequence::freebuf (tmp);
        this->buffer_ = _TAO_Unbounded_Sequence_TAO_SCIOPEndpointSequence::allocbuf (rhs.maximum_);
      }
    }
    else
      this->buffer_ = _TAO_Unbounded_Sequence_TAO_SCIOPEndpointSequence::allocbuf (rhs.maximum_);

    TAO_Unbounded_Base_Sequence::operator= (rhs);

    TAO_SCIOP_Endpoint_Info *tmp1 = ACE_reinterpret_cast (TAO_SCIOP_Endpoint_Info *, this->buffer_);
    TAO_SCIOP_Endpoint_Info * const tmp2 = ACE_reinterpret_cast (TAO_SCIOP_Endpoint_Info * ACE_CAST_CONST, rhs.buffer_);

    for (CORBA::ULong i = 0; i < this->length_; ++i)
      tmp1[i] = tmp2[i];

    return *this;
  }

  // = Accessors.
  ACE_INLINE TAO_SCIOP_Endpoint_Info &
  _TAO_Unbounded_Sequence_TAO_SCIOPEndpointSequence::operator[] (CORBA::ULong i)
  // operator []
  {
    ACE_ASSERT (i < this->maximum_);
    TAO_SCIOP_Endpoint_Info* tmp = ACE_reinterpret_cast(TAO_SCIOP_Endpoint_Info*,this->buffer_);
    return tmp[i];
  }

  ACE_INLINE const TAO_SCIOP_Endpoint_Info &
  _TAO_Unbounded_Sequence_TAO_SCIOPEndpointSequence::operator[] (CORBA::ULong i) const
  // operator []
  {
    ACE_ASSERT (i < this->maximum_);
    TAO_SCIOP_Endpoint_Info * const tmp = ACE_reinterpret_cast (TAO_SCIOP_Endpoint_Info* ACE_CAST_CONST, this->buffer_);
    return tmp[i];
  }

  // Implement the TAO_Base_Sequence methods (see Sequence.h)

  ACE_INLINE TAO_SCIOP_Endpoint_Info *
  _TAO_Unbounded_Sequence_TAO_SCIOPEndpointSequence::get_buffer (CORBA::Boolean orphan)
  {
    TAO_SCIOP_Endpoint_Info *result = 0;
    if (orphan == 0)
    {
      // We retain ownership.
      if (this->buffer_ == 0)
      {
        result = _TAO_Unbounded_Sequence_TAO_SCIOPEndpointSequence::allocbuf (this->length_);
        this->buffer_ = result;
        this->release_ = 1;
      }
      else
      {
        result = ACE_reinterpret_cast (TAO_SCIOP_Endpoint_Info*, this->buffer_);
      }
    }
    else // if (orphan == 1)
    {
      if (this->release_ != 0)
      {
        // We set the state back to default and relinquish
        // ownership.
        result = ACE_reinterpret_cast(TAO_SCIOP_Endpoint_Info*,this->buffer_);
        this->maximum_ = 0;
        this->length_ = 0;
        this->buffer_ = 0;
        this->release_ = 0;
      }
    }
    return result;
  }

  ACE_INLINE const TAO_SCIOP_Endpoint_Info *
  _TAO_Unbounded_Sequence_TAO_SCIOPEndpointSequence::get_buffer (void) const
  {
    return ACE_reinterpret_cast(const TAO_SCIOP_Endpoint_Info * ACE_CAST_CONST, this->buffer_);
  }

  ACE_INLINE void
  _TAO_Unbounded_Sequence_TAO_SCIOPEndpointSequence::replace (CORBA::ULong max,
  CORBA::ULong length,
  TAO_SCIOP_Endpoint_Info *data,
  CORBA::Boolean release)
  {
    this->maximum_ = max;
    this->length_ = length;
    if (this->buffer_ && this->release_ == 1)
    {
      TAO_SCIOP_Endpoint_Info *tmp = ACE_reinterpret_cast(TAO_SCIOP_Endpoint_Info*,this->buffer_);
      _TAO_Unbounded_Sequence_TAO_SCIOPEndpointSequence::freebuf (tmp);
    }
    this->buffer_ = data;
    this->release_ = release;
  }

#endif /* end #if !defined */


#endif /* !TAO_USE_SEQUENCE_TEMPLATES */

#if !defined (_TAO_SCIOPENDPOINTSEQUENCE_CI_)
#define _TAO_SCIOPENDPOINTSEQUENCE_CI_

// *************************************************************
// Inline operations for class TAO_SCIOPEndpointSequence_var
// *************************************************************

ACE_INLINE
TAO_SCIOPEndpointSequence_var::TAO_SCIOPEndpointSequence_var (void) // default constructor
  : ptr_ (0)
{}

ACE_INLINE
TAO_SCIOPEndpointSequence_var::TAO_SCIOPEndpointSequence_var (TAO_SCIOPEndpointSequence *p)
  : ptr_ (p)
{}

ACE_INLINE
TAO_SCIOPEndpointSequence_var::TAO_SCIOPEndpointSequence_var (const ::TAO_SCIOPEndpointSequence_var &p) // copy constructor
{
  if (p.ptr_)
    ACE_NEW (this->ptr_, ::TAO_SCIOPEndpointSequence (*p.ptr_));
  else
    this->ptr_ = 0;
}

ACE_INLINE
TAO_SCIOPEndpointSequence_var::~TAO_SCIOPEndpointSequence_var (void) // destructor
{
  delete this->ptr_;
}

ACE_INLINE TAO_SCIOPEndpointSequence_var &
TAO_SCIOPEndpointSequence_var::operator= (TAO_SCIOPEndpointSequence *p)
{
  delete this->ptr_;
  this->ptr_ = p;
  return *this;
}

ACE_INLINE TAO_SCIOPEndpointSequence_var &
TAO_SCIOPEndpointSequence_var::operator= (const ::TAO_SCIOPEndpointSequence_var &p) // deep copy
{
  if (this != &p)
  {
    delete this->ptr_;
    ACE_NEW_RETURN (this->ptr_, ::TAO_SCIOPEndpointSequence (*p.ptr_), *this);
  }
  return *this;
}

ACE_INLINE const ::TAO_SCIOPEndpointSequence *
TAO_SCIOPEndpointSequence_var::operator-> (void) const
{
  return this->ptr_;
}

ACE_INLINE ::TAO_SCIOPEndpointSequence *
TAO_SCIOPEndpointSequence_var::operator-> (void)
{
  return this->ptr_;
}

ACE_INLINE
TAO_SCIOPEndpointSequence_var::operator const ::TAO_SCIOPEndpointSequence &() const // cast
{
  return *this->ptr_;
}

ACE_INLINE
TAO_SCIOPEndpointSequence_var::operator ::TAO_SCIOPEndpointSequence &() // cast
{
  return *this->ptr_;
}

ACE_INLINE
TAO_SCIOPEndpointSequence_var::operator ::TAO_SCIOPEndpointSequence &() const // cast
{
  return *this->ptr_;
}

// variable-size types only
ACE_INLINE
TAO_SCIOPEndpointSequence_var::operator ::TAO_SCIOPEndpointSequence *&() // cast
{
  return this->ptr_;
}

ACE_INLINE TAO_SCIOP_Endpoint_Info &
TAO_SCIOPEndpointSequence_var::operator[] (CORBA::ULong index)
{
  return this->ptr_->operator[] (index);
}

ACE_INLINE const ::TAO_SCIOPEndpointSequence &
TAO_SCIOPEndpointSequence_var::in (void) const
{
  return *this->ptr_;
}

ACE_INLINE ::TAO_SCIOPEndpointSequence &
TAO_SCIOPEndpointSequence_var::inout (void)
{
  return *this->ptr_;
}

// mapping for variable size
ACE_INLINE ::TAO_SCIOPEndpointSequence *&
TAO_SCIOPEndpointSequence_var::out (void)
{
  delete this->ptr_;
  this->ptr_ = 0;
  return this->ptr_;
}

ACE_INLINE ::TAO_SCIOPEndpointSequence *
TAO_SCIOPEndpointSequence_var::_retn (void)
{
  ::TAO_SCIOPEndpointSequence *tmp = this->ptr_;
  this->ptr_ = 0;
  return tmp;
}

ACE_INLINE ::TAO_SCIOPEndpointSequence *
TAO_SCIOPEndpointSequence_var::ptr (void) const
{
  return this->ptr_;
}

#endif /* end #if !defined */

ACE_INLINE CORBA::Boolean operator<< (TAO_OutputCDR &strm, const TAO_SCIOP_Endpoint_Info &_tao_aggregate)
{
  if (
    (strm << _tao_aggregate.host.in ()) &&
    (strm << _tao_aggregate.port) &&
    (strm << _tao_aggregate.priority)
  )
    return 1;
  else
    return 0;

}

ACE_INLINE CORBA::Boolean operator>> (TAO_InputCDR &strm, TAO_SCIOP_Endpoint_Info &_tao_aggregate)
{
  if (
    (strm >> _tao_aggregate.host.out ()) &&
    (strm >> _tao_aggregate.port) &&
    (strm >> _tao_aggregate.priority)
  )
    return 1;
  else
    return 0;

}


#if !defined _TAO_CDR_OP_TAO_SCIOPEndpointSequence_I_
#define _TAO_CDR_OP_TAO_SCIOPEndpointSequence_I_

CORBA::Boolean TAO_Export operator<< (
    TAO_OutputCDR &,
    const TAO_SCIOPEndpointSequence &
  );
CORBA::Boolean TAO_Export operator>> (
    TAO_InputCDR &,
    TAO_SCIOPEndpointSequence &
  );

#endif /* _TAO_CDR_OP_TAO_SCIOPEndpointSequence_I_ */

