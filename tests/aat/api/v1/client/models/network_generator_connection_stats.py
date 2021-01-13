# coding: utf-8

"""
    OpenPerf API

    REST API interface for OpenPerf  # noqa: E501

    OpenAPI spec version: 1
    Contact: support@spirent.com
    Generated by: https://github.com/swagger-api/swagger-codegen.git
"""


import pprint
import re  # noqa: F401

import six


class NetworkGeneratorConnectionStats(object):
    """NOTE: This class is auto generated by the swagger code generator program.

    Do not edit the class manually.
    """

    """
    Attributes:
      swagger_types (dict): The key is attribute name
                            and the value is attribute type.
      attribute_map (dict): The key is attribute name
                            and the value is json key in definition.
    """
    swagger_types = {
        'attempted': 'int',
        'successful': 'int',
        'errors': 'int',
        'closed': 'int'
    }

    attribute_map = {
        'attempted': 'attempted',
        'successful': 'successful',
        'errors': 'errors',
        'closed': 'closed'
    }

    def __init__(self, attempted=None, successful=None, errors=None, closed=None):  # noqa: E501
        """NetworkGeneratorConnectionStats - a model defined in Swagger"""  # noqa: E501

        self._attempted = None
        self._successful = None
        self._errors = None
        self._closed = None
        self.discriminator = None

        self.attempted = attempted
        self.successful = successful
        self.errors = errors
        self.closed = closed

    @property
    def attempted(self):
        """Gets the attempted of this NetworkGeneratorConnectionStats.  # noqa: E501

        The number of attempts to establish connections  # noqa: E501

        :return: The attempted of this NetworkGeneratorConnectionStats.  # noqa: E501
        :rtype: int
        """
        return self._attempted

    @attempted.setter
    def attempted(self, attempted):
        """Sets the attempted of this NetworkGeneratorConnectionStats.

        The number of attempts to establish connections  # noqa: E501

        :param attempted: The attempted of this NetworkGeneratorConnectionStats.  # noqa: E501
        :type: int
        """
        self._attempted = attempted

    @property
    def successful(self):
        """Gets the successful of this NetworkGeneratorConnectionStats.  # noqa: E501

        The actual number of established connections  # noqa: E501

        :return: The successful of this NetworkGeneratorConnectionStats.  # noqa: E501
        :rtype: int
        """
        return self._successful

    @successful.setter
    def successful(self, successful):
        """Sets the successful of this NetworkGeneratorConnectionStats.

        The actual number of established connections  # noqa: E501

        :param successful: The successful of this NetworkGeneratorConnectionStats.  # noqa: E501
        :type: int
        """
        self._successful = successful

    @property
    def errors(self):
        """Gets the errors of this NetworkGeneratorConnectionStats.  # noqa: E501

        The number of errors observed during connecting process  # noqa: E501

        :return: The errors of this NetworkGeneratorConnectionStats.  # noqa: E501
        :rtype: int
        """
        return self._errors

    @errors.setter
    def errors(self, errors):
        """Sets the errors of this NetworkGeneratorConnectionStats.

        The number of errors observed during connecting process  # noqa: E501

        :param errors: The errors of this NetworkGeneratorConnectionStats.  # noqa: E501
        :type: int
        """
        self._errors = errors

    @property
    def closed(self):
        """Gets the closed of this NetworkGeneratorConnectionStats.  # noqa: E501

        The number of closed connections  # noqa: E501

        :return: The closed of this NetworkGeneratorConnectionStats.  # noqa: E501
        :rtype: int
        """
        return self._closed

    @closed.setter
    def closed(self, closed):
        """Sets the closed of this NetworkGeneratorConnectionStats.

        The number of closed connections  # noqa: E501

        :param closed: The closed of this NetworkGeneratorConnectionStats.  # noqa: E501
        :type: int
        """
        self._closed = closed

    def to_dict(self):
        """Returns the model properties as a dict"""
        result = {}

        for attr, _ in six.iteritems(self.swagger_types):
            value = getattr(self, attr)
            if isinstance(value, list):
                result[attr] = list(map(
                    lambda x: x.to_dict() if hasattr(x, "to_dict") else x,
                    value
                ))
            elif hasattr(value, "to_dict"):
                result[attr] = value.to_dict()
            elif isinstance(value, dict):
                result[attr] = dict(map(
                    lambda item: (item[0], item[1].to_dict())
                    if hasattr(item[1], "to_dict") else item,
                    value.items()
                ))
            else:
                result[attr] = value
        if issubclass(NetworkGeneratorConnectionStats, dict):
            for key, value in self.items():
                result[key] = value

        return result

    def to_str(self):
        """Returns the string representation of the model"""
        return pprint.pformat(self.to_dict())

    def __repr__(self):
        """For `print` and `pprint`"""
        return self.to_str()

    def __eq__(self, other):
        """Returns true if both objects are equal"""
        if not isinstance(other, NetworkGeneratorConnectionStats):
            return False

        return self.__dict__ == other.__dict__

    def __ne__(self, other):
        """Returns true if both objects are not equal"""
        return not self == other