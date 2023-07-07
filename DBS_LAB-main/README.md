# DBS_LAB

taking all the primary-key attributes
from all the related entity sets serves to identify a particular tuple, but for one-toone,
many-to-one, and one-to-many relationship sets, this turns out to be a larger
set of attributes than we need in the primary key. The primary key is instead
chosen as follows:
• For a binary many-to-many relationship, the union of the primary-key attributes
from the participating entity sets becomes the primary key.
• For a binary one-to-one relationship set, the primary key of either entity set
can be chosen as the primary key. The choice can be made arbitrarily.
• For a binary many-to-one or one-to-many relationship set, the primary key of
the entity set on the “many” side of the relationship set serves as the primary
key.


In general, the schema for the relationship set linking a weak entity set to its
corresponding strong entity set is redundant and does not need to be present in
a relational database design based upon an E-R diagram.


A to B (many to one), total participation of A then combine A and AB


the case of one-to-one relationships, the relation schema for the relationship
set can be combined with the schemas for either of the entity sets


We can combine schemas even if the participation is partial by using null
values.


we consider the foreign-key constraints that would have appeared in
the schema representing the relationship set. There would have been foreign-key
constraints referencing each of the entity sets participating in the relationship
set. We drop the constraint referencing the entity set into whose schema the
relationship set schema is merged, and add the other foreign-key constraints to
the combined schema.
