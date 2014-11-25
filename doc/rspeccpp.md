# RSpec in c++

# OK not really...

But we can create a reasonable facsimile of the `it` method
using c++ lambdas.

First, here it is in Ruby:

~~~~
@@@ ruby
  it "floats my boat" do
    boat.should be_floatable
  end
~~~~

What's that look like in c++?

### Wait... let's back up one step...

Why might we want to write spec-style testing in c++?


# Why spec style unit tests?

Several reasons:

* Unit testing is so 1999. `assert`, `assert`, `CPPUNIT_ASSERT`, &c. &c.
&c. *ad nauseum*. Boring.
* RSpecs are more fun and easier to write
* Just because we can (<- best reason)


# Spec in Ruby

Lets look at that Boat again:

~~~~
@@@ ruby
  it "floats my boat" do
    boat.should be_floatable
  end
~~~~

We have: 

1. an `it` method, with signature `def it (desc=nil, *args, &block)`
2. evidently, the description is unecessary, and the `*args` are clearly
   optional (we didn't pass any `*args`). 
3. The block delimited by `do` and `end` is the &lambda;, where the good stuff lives.

### We can totally do that in c++!


# Spec in c++

Like so:

~~~~
@@@ cpp

Spec spec;

spec.it ("floats my boat", DO {
  return (true == boat.is_floatable());
});
~~~~

Two observations:

1. Not as pretty as Ruby spec;
2. *way* prettier than your daddy's unit test.

### A third observation: not your daddy's c++ either.


# What just happened...?

Welcome to c++ with lambdas (&lambda;).

Let's rewrite our spec without the DO macro:

~~~~
@@@ cpp
Spec spec;

spec.it ("floats my boat", [&](const char *)->bool {
  return (true == boat.is_floatable());
});
~~~~

Aha, that looks better. Or worse, depending on your point of view:
we've exposed the &lambda;.

So our `it` method takes a `const char *` and an anonymous function
returning a `bool`.
Cool.

----
----
----

### Also...

Not advocating, merely illustrating:

~~~~
@@@ cpp
#define DO [&](const char *)-> bool
~~~~

# Prototyping Spec.it()

~~~~
@@@ cpp
typedef const char * Description;
typedef void (*Describer)(const char *, Description);

class Spec {

public:

  char buf[512]; // yeah, I don't like this either.

  void it (Description desc, function<bool(Description)> test) {

    Describer d; // Pretty printing callback
    sprintf(buf, desc);
    try {
      CPPUNIT_ASSERT(test(desc));
      d = describe_pass; // prints green
    } catch (CppUnit::Exception e) {
      d = describe_fail; // prints red
    }
    d(INDENT4, buf); // call the pretty printer
  }
};
~~~~

# Let's run it...

![Red green in c++](/images/redgreencpp.png "So cool.")


### Check out that (PENDING)

Implementing `xit` in c++ is as trivial as it is in RSpec. Left as
exercise for the reader.

# Silly &lambda;, Y U no use callback?

That's a really good question. `Spec.it` *doesn't care where the
function argument comes from*. It (heh) only cares about the signature.

But using our anonymous &lambda; we get loads of benefits:

1. Anonymous function declared in place encourages tidy testing.
2. Closure if we want it. (Probably not necessary.)
3. Spec-like for a reason. Declaring callbacks elsewhere violates the
   *Tao of Spec*.
 

# What can we conclude?

1. Spec style testing *is* doable in c++, and it's not that bad.
2. Template juju would (probably) remove the necessity of declaring an instance
   of `Spec`.
3. Logging details (pretty printing) require buffer (or string) management.
4. We will not speak of matchers at this time.

### Stay tuned for the template version

## Questions?

# Lagniappe

Copy this to `floatable.rb` somewhere the `rspec` gem is installed:

~~~~
@@@ ruby
#!/usr/bin/env ruby

require 'rspec'

class Boat
  def floatable?
    true
  end
end

describe Boat do
  it "floats my boat" do
    boat = Boat.new
    boat.should be_floatable
  end
end
~~~~

Execute:

~~~~
@@@ sh
$ rspec floatable.rb
~~~~
