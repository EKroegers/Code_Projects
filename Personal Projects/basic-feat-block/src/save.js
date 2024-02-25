/**
 * React hook that is used to mark the block wrapper element.
 * It provides all the necessary props like the class name.
 *
 * @see https://developer.wordpress.org/block-editor/reference-guides/packages/packages-block-editor/#useblockprops
 */
import { useBlockProps } from '@wordpress/block-editor';

/**
 * The save function defines the way in which the different attributes should
 * be combined into the final markup, which is then serialized by the block
 * editor into `post_content`.
 *
 * @see https://developer.wordpress.org/block-editor/reference-guides/block-api/block-edit-save/#save
 *
 * @param {Object} props            Properties passed to the function.
 * @param {Object} props.attributes Available block attributes.
 *
 * @return {Element} Element to render.
 */
export default function save( { attributes } ) {
	const { 
    featTitle, 
    featPrerequisites, 
    featBenefits,
    showSpecialField, featSpecials } = attributes;

	// If there is no content, which could happen if the block
	// is loaded from a template/pattern, return null. In this case, block
	// rendering will be handled by the render.php file.
	if ( ! featTitle ) {
		return null;
	}
  else if ( ! featPrerequisites ) {
		return null;
	}
  else if ( ! featBenefits ) {
		return null;
	}
  else if ( ! showSpecialField ) {
		return null;
	}
  else if ( ! featSpecials ) {
		return null;
	}

	return (
    <div { ...useBlockProps.save() }>
        <h4>{featTitle}</h4>
        <p><strong>Prerequisite(s): </strong>{featPrerequisites}</p>
        <p><strong>Benefit(s): </strong>{featBenefits}</p>
        { showSpecialField &&
          <p><strong>Special: </strong>{featSpecials}</p>
        }
    </div>
  );
}

/**
 * Dear Future Me,
 * If you're back here wondering why your static blocks have validation errors
 * It's because the dynamic content within them changed and you stopped at the
 * "Handling dynamic content in statically rendered blocks" part of this
 * guide (https://developer.wordpress.org/block-editor/getting-started/tutorial/)
 * because you thought you didn't need it
 */